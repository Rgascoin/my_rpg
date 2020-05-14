/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc
*/

#include "my_rpg.h"

static bool load_rest_png(scenes_t *scene, textures_t **textures)
{
    const char *name[] = {"rest_chara", "rest_buble", "rest_face", "inv", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    return (true);
}

static bool place_rest_png(scenes_t *scene)
{
    sfVector2f pos = {250, 420};
    textures_t *textures[] = {NULL, NULL, NULL, NULL, NULL};

    if (load_rest_png(scene, textures) == false)
        return (false);
    sfSprite_setPosition(textures[0]->sf_sprite, pos);
    pos.y = 370;
    pos.x = 200;
    sfSprite_setPosition(textures[1]->sf_sprite, pos);
    pos.y = 350;
    sfSprite_setPosition(textures[2]->sf_sprite, pos);
    pos.y = 567;
    pos.x = 475;
    sfSprite_setPosition(textures[3]->sf_sprite, pos);
    return (true);
}

bool init_npc(scenes_t *scene)
{
    if (place_rest_png(scene) == false)
        return (false);
    return (true);
}