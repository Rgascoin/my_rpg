/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** texture
*/

#include "my_rpg.h"

bool texture_error_run(textures_t *tmp, textures_t *texture,
const char **assets, int i)
{
    for (tmp = texture; tmp != NULL; tmp = tmp->next) {
        if ((get_texture(tmp, assets[i])) != NULL)
            break;
    }
    if (tmp == NULL)
        return (false);
    return (true);
}

bool load_error_texture(textures_t *texture, const char **assets)
{
    textures_t *tmp = NULL;

    for (int i = 0; assets[i] != NULL; i++) {
        if (texture_error_run(tmp, texture, assets, i) == false) {
            my_printf("Invalid config file (texture).\n");
            return (false);
        }
    }
    return (true);
}