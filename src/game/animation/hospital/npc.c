/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc
*/

#include "my_rpg.h"
#include "my_gamestate.h"

bool animate_rest_bubble(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    textures_t *face = NULL;
    textures_t *buble = NULL;

    if (!scene || (face = get_texture(scene->textures, "rest_face")) == NULL
    || (buble = get_texture(scene->textures, "rest_buble")) == NULL)
        return (false);
    if (win->game->player->pos.y >= 420 && win->game->player->pos.y <= 455
    && win->game->player->pos.x >= 225 && win->game->player->pos.x <= 270) {
        face->visible = true;
        buble->visible = true;
    } else {
        face->visible = false;
        buble->visible = false;
    }
    return (true);
}

bool animate_rest(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = NULL;
    textures_t *texture = NULL;

    if ((scene = get_scene(win->scenes, scene_name)) == NULL
    || (texture = get_texture(scene->textures, "rest_room")) == NULL)
        return (false);
    if (texture->time >= 0.08) {
        animate_sprite(texture->sf_sprite, 220, 11634);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
    if (win->game->player->pos.y >= 455 && win->game->player->pos.y <= 460
    && win->game->player->pos.x >= 695 && win->game->player->pos.x <= 765)
        texture->visible = true;
    else
        texture->visible = false;
    return (true);
}