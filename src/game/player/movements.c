/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** movements
*/

#include "my_rpg.h"
#include "my_gamestate.h"

static bool player_movements_loader(scenes_t *scene, textures_t **textures)
{
    const char *name[] = {"player_s", "player_face", "player_idle",
    "player_n", "player_w", "player_e", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    return (true);
}

bool player_movements(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    textures_t *textures[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    if (!scene || player_movements_loader(scene, textures) == false)
        return (false);
    for (int i = 0; textures[i] != NULL; i++)
        sfSprite_setPosition(textures[i]->sf_sprite, win->game->player->pos);
    return (true);
}