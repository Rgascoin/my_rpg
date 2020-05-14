/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_game.h"

bool animate_player(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    if (!scene)
        return (false);
    if (hide_animation(win) == false)
        return (false);
    animate_south(scene);
    animate_north(scene);
    animate_east(scene);
    animate_west(scene);
    return (true);
}