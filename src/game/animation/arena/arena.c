/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** arena
*/

#include "my_rpg.h"
#include "my_gamestate.h"

bool animate_arena(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = NULL;
    textures_t *texture = NULL;

    if ((scene = get_scene(win->scenes, scene_name)) == NULL
    || (texture = get_texture(scene->textures, "arena_buble")) == NULL)
        return (false);
    if (texture->time >= 0.08) {
        animate_sprite(texture->sf_sprite, 220, 10034);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
    if (win->game->player->pos.y >= 300 && win->game->player->pos.y <= 310
    && win->game->player->pos.x >= 770 && win->game->player->pos.x <= 820)
        texture->visible = true;
    else
        texture->visible = false;
    return (true);
}