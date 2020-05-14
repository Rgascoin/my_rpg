/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** animator
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_game.h"

bool animate_management(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    if (!player_standing(scene)
    || !enemie_standing(scene, win->game->fight->player_2))
        return (false);
    return (true);
}