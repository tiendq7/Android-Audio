// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/platform_device.h>
#include <sound/soc.h>

static struct snd_soc_dai_link my_dai_link = {
    .name = "MyCodecLink",
    .stream_name = "My Audio",
    .cpu_dai_name = "I2S0",
    .platform_name = "my-platform",
    .codec_dai_name = "mycodec-dai",
    .codec_name = "mycodec.1-001a",
};

static struct snd_soc_card my_snd_card = {
    .name = "My ALSA Machine",
    .owner = THIS_MODULE,
    .dai_link = &my_dai_link,
    .num_links = 1,
};

static int my_machine_probe(struct platform_device *pdev)
{
    my_snd_card.dev = &pdev->dev;
    return devm_snd_soc_register_card(&pdev->dev, &my_snd_card);
}

static struct platform_driver my_machine_driver = {
    .driver = {
        .name = "my_machine",
        .owner = THIS_MODULE,
    },
    .probe = my_machine_probe,
};

module_platform_driver(my_machine_driver);

MODULE_DESCRIPTION("My ALSA SoC Machine Driver");
MODULE_AUTHOR("Your Name");
MODULE_LICENSE("GPL");
