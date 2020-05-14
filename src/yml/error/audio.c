/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** audio
*/

#include "my_rpg.h"

bool audio_error_run(audios_t *audio, const char **assets, audios_t *tmp, int i)
{
    for (tmp = audio; tmp != NULL; tmp = tmp->next) {
        if ((get_audio(tmp, assets[i])) != NULL)
            break;
    }
    if (tmp == NULL)
        return (false);
    return (true);
}

bool load_error_audio(audios_t *audio, const char **assets)
{
    audios_t *tmp = NULL;

    for (int i = 0; assets[i] != NULL; i++) {
        if (audio_error_run(audio, assets, tmp, i) == false) {
            my_printf("Invalid config file (audio).\n");
            return (false);
        }
    }
    return (true);
}