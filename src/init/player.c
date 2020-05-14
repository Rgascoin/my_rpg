/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "my_rpg.h"

static bool player_size(scenes_t *scene)
{
    sfVector2f scale = {0.5, 0.5};
    textures_t *textures[] = {NULL, NULL, NULL, NULL, NULL, NULL};
    const char *name[] = {"player_s", "player_e", "player_n", "player_w",
    "player_idle", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    for (int i = 0; textures[i] != NULL; i++) {
        sfSprite_setScale(textures[i]->sf_sprite,
        scale);
    }
    scale.x = 1.2;
    scale.y = 1.4;
    sfSprite_setScale(get_texture(scene->textures, "inv")->sf_sprite, scale);
    return (true);
}

bool init_player(scenes_t *scene)
{
    if (player_size(scene) == false)
        return (false);
    return (true);
}