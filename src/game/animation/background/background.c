/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** background
*/

#include "my_rpg.h"
#include "my_gamestate.h"

bool animate_background(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = NULL;
    textures_t *texture = NULL;

    if ((scene = get_scene(win->scenes, scene_name)) == NULL
    || (texture = get_texture(scene->textures, "bg")) == NULL)
        return (false);
    if (texture->time >= 0.01) {
        animate_sprite(texture->sf_sprite, 1280, 14080);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
    return (true);
}