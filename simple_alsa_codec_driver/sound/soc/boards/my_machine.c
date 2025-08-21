// SPDX-License-Identifier: GPL-2.0
// my_machine.c - Minimal ASoC machine driver (OF-only)

#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>
#include <sound/soc.h>

static int my_parse_dai_fmt(struct device *dev, struct device_node *np_codec,
                            struct device_node *np_cpu, unsigned int *dai_fmt)
{
    if (!np_codec || !np_cpu) {
        dev_err(dev, "missing codec or cpu node\n");
        return -EINVAL;
    }
    unsigned int fmt = SND_SOC_DAIFMT_I2S |
                       SND_SOC_DAIFMT_NB_NF |
                       SND_SOC_DAIFMT_CBM_CFM;

    if (of_property_read_bool(np_codec, "mycodec,master")) {
        fmt |= SND_SOC_DAIFMT_CBS_CFS;  // Codec is master
    } else {
        fmt |= SND_SOC_DAIFMT_CBM_CFM;  // Codec is slave
    }           
    *dai_fmt = fmt;
    return 0;
}

static int my_machine_probe(struct platform_device *pdev)
{
    struct device *dev = &pdev->dev;
    struct device_node *np = dev->of_node;
    struct device_node *np_cpu = NULL, *np_codec = NULL;
    struct snd_soc_card *card;
    struct snd_soc_dai_link *link;
    struct snd_soc_dai_link_component *cpus, *codecs, *platforms;
    unsigned int dai_fmt;
    int ret;

    if (!np)
        return -EINVAL;

    np_cpu  = of_get_child_by_name(np, "cpu");
    np_codec = of_get_child_by_name(np, "codec");
    if (!np_cpu || !np_codec) {
        dev_err(dev, "missing 'cpu' or 'codec' subnode\n");
        ret = -EINVAL;
        goto put_nodes;
    }

    card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
    if (!card) { ret = -ENOMEM; goto put_nodes; }

    link = devm_kzalloc(dev, sizeof(*link), GFP_KERNEL);
    if (!link) { ret = -ENOMEM; goto put_nodes; }

    card->dev      = dev;
    card->owner    = THIS_MODULE;
    card->driver_name = "my-machine";          
    card->num_links = 1;
    card->dai_link  = link;

    link->name        = "MyCodecLink";
    link->stream_name = "My Audio";

    /* CPU component */
    cpus = devm_kzalloc(dev, sizeof(*cpus), GFP_KERNEL);
    if (!cpus) { ret = -ENOMEM; goto put_nodes; }
    link->cpus = cpus;
    link->num_cpus = 1;
    {
        struct of_phandle_args args;
        ret = of_parse_phandle_with_args(np_cpu, "sound-dai", "#sound-dai-cells", 0, &args);
        if (ret) { dev_err(dev, "parse cpu sound-dai failed\n"); goto put_nodes; }
        cpus->of_node = args.np;
        cpus->dai_name = "mycpu-dai"; 
        cpus->name = "mycpu";  
    }

    /* CODEC component */
    codecs = devm_kzalloc(dev, sizeof(*codecs), GFP_KERNEL);
    if (!codecs) { ret = -ENOMEM; goto put_nodes; }
    link->codecs = codecs;
    link->num_codecs = 1;
    {
        struct of_phandle_args args;
        ret = of_parse_phandle_with_args(np_codec, "sound-dai", "#sound-dai-cells", 0, &args);
        if (ret) { dev_err(dev, "parse codec sound-dai failed\n"); goto put_nodes; }
        codecs->of_node = args.np;
        codecs->dai_name = "mycodec-dai";
        codecs->name = "mycodec"; 
    }
    /* Platform component */
    platforms = devm_kzalloc(dev, sizeof(*platforms), GFP_KERNEL);
    if (!platforms) { ret = -ENOMEM; goto put_nodes; }
    link->platforms = platforms;
    link->num_platforms = 1;
    platforms->of_node = cpus->of_node;

    /* DAI format (I2S + codec master) */
    ret = my_parse_dai_fmt(dev, codecs->of_node, cpus->of_node, &dai_fmt);
    if (ret) goto put_nodes;
    link->dai_fmt = dai_fmt;

    snd_soc_of_parse_card_name(card, "model");

    ret = devm_snd_soc_register_card(dev, card);
    if (ret)
        dev_err(dev, "snd_soc_register_card failed: %d\n", ret);

put_nodes:
    of_node_put(np_cpu);
    of_node_put(np_codec);
    return ret;
}

static const struct of_device_id my_machine_of_match[] = {
    { .compatible = "myvendor,my-machine", },
    { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, my_machine_of_match);

static struct platform_driver my_machine_driver = {
    .driver = {
        .name = "my-machine",
        .of_match_table = my_machine_of_match,
    },
    .probe = my_machine_probe,
};
module_platform_driver(my_machine_driver);

MODULE_DESCRIPTION("My ASoC Machine (OF phandle only)");
MODULE_AUTHOR("Your Name");
MODULE_LICENSE("GPL");
