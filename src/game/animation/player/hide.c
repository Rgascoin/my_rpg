/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hide
*/

#include "my_rpg.h"
#include "my_gamestate.h"

static bool hide_player_load(scenes_t *scene, textures_t **textures)
{
    const char *name[] = {"player_s", "player_n", "player_w", "player_e",
    "player_idle", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    return (true);
}

static bool hide_player(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    textures_t *textures[] = {NULL, NULL, NULL, NULL, NULL, NULL};

    if (!scene || hide_player_load(scene, textures) == false)
        return (false);
    textures[0]->visible = false;
    textures[1]->visible = false;
    textures[2]->visible = false;
    textures[3]->visible = false;
    textures[4]->visible = true;
    return (true);
}

bool hide_animation(win_t *win)
{
    if (!sfKeyboard_isKeyPressed(sfKeyDown)
    && !sfKeyboard_isKeyPressed(sfKeyRight)
    && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (hide_player(win) == false)
            return (false);
    }
    return (true);
}