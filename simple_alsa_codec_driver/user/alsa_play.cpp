#include <alsa/asoundlib.h>
#include <iostream>

int main() {
    snd_pcm_t *pcm_handle;
    snd_pcm_open(&pcm_handle, "hw:0,0", SND_PCM_STREAM_PLAYBACK, 0);
    snd_pcm_set_params(pcm_handle, SND_PCM_FORMAT_S16_LE,
                       SND_PCM_ACCESS_RW_INTERLEAVED,
                       2, 44100, 1, 500000);

    FILE *fp = fopen("test.wav", "rb");
    fseek(fp, 44, SEEK_SET);
    char buffer[4096];
    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        snd_pcm_writei(pcm_handle, buffer, sizeof(buffer) / 4);
    }

    fclose(fp);
    snd_pcm_close(pcm_handle);
    return 0;
}
