/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** life
*/

#include "my_rpg.h"
#include "my_gamestate.h"

void move_circle(scenes_t *scene, sfVector2f *pos)
{
    pos->y = 500;
    pos->x = 250;
    sfSprite_setPosition(get_texture(scene->textures, "circle1")->sf_sprite,
    *pos);
    pos->x = 590;
    sfSprite_setPosition(get_texture(scene->textures, "circle2")->sf_sprite,
    *pos);
    pos->x = 950;
    sfSprite_setPosition(get_texture(scene->textures, "circle3")->sf_sprite,
    *pos);
}

void move_spell(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    sfVector2f pos = {650, 200};

    sfSprite_setPosition(get_texture(scene->textures, "punch_hud")->sf_sprite,
    pos);
    pos.y = 300;
    sfSprite_setPosition(get_texture(scene->textures, "kick_hud")->sf_sprite,
    pos);
    pos.y = 400;
    sfSprite_setPosition(get_texture(scene->textures, "upercut_hud")->sf_sprite,
    pos);
    move_circle(scene, &pos);
    return;
}