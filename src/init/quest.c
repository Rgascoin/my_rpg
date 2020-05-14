/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest
*/

#include "my_rpg.h"

static bool load_quest_png(scenes_t *scene, textures_t **textures)
{
    const char *name[] = {"quest_chara", "quest_buble_01", "quest_buble_02",
    "quest_ask", "quest_empty", "quest_complete_buble", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    return (true);
}

static bool place_quest_png(scenes_t *scene)
{
    sfVector2f pos = {450, 225};
    sfVector2f scale = {0.25, 0.25};
    textures_t *textures[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    if (load_quest_png(scene, textures) == false)
        return (false);
    sfSprite_setPosition(textures[0]->sf_sprite, pos);
    pos.y = 175;
    pos.x = 400;
    for (int i = 1; textures[i] != NULL; i++) {
        sfSprite_setPosition(textures[i]->sf_sprite, pos);
        sfSprite_setScale(textures[i]->sf_sprite, scale);
    }
    return (true);
}

bool init_quest(scenes_t *scene)
{
    if (place_quest_png(scene) == false)
        return (false);
    return (true);
}