/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** death
*/

#include "my_rpg.h"
#include "my_gamestate.h"

void move_cross(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    sfVector2f pos = {650, 200};

    pos.y = 500;
    pos.x = 250;
    (win->game->player->lose >= 1) ? sfSprite_setPosition(
    get_texture(scene->textures, "cross1")->sf_sprite, pos) : 0;
    (win->game->player->lose >= 1) ?
    get_texture(scene->textures, "cross1")->visible = true : 0;
    pos.x = 590;
    (win->game->player->lose >= 2) ? sfSprite_setPosition(
    get_texture(scene->textures, "cross2")->sf_sprite, pos) : 0;
    (win->game->player->lose >= 2) ?
    get_texture(scene->textures, "cross2")->visible = true : 0;
    pos.x = 950;
    (win->game->player->lose >= 3) ?
    sfSprite_setPosition(get_texture(scene->textures, "cross3")->sf_sprite, pos)
    : 0;
    (win->game->player->lose >= 3) ?
    get_texture(scene->textures, "cross3")->visible = true : 0;
}