/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** print
*/

#include "my_rpg.h"
#include "my_gamestate.h"

void show_available_attack(scenes_t *scene, win_t *win)
{
    sfVector2f pos = {450, 500};

    sfRectangleShape_setPosition(get_button(scene->buttons,
    "punch_hud")->sf_rect, pos);
    pos.y = 600;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "kick_hud")->sf_rect, pos);
    pos.x = 750;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "back_hud")->sf_rect, pos);
    pos.y = 500;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "upercut_hud")->sf_rect, pos);
    (win->game->fight->player_1->max_strength < 5) ?
    get_texture(scene->textures, "cross")->visible = true : 0;
}

void show_attack(win_t *win)
{
    const char *name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, name);
    sfVector2f pos = {-200, -100};

    sfRectangleShape_setPosition(get_button(scene->buttons,
    "attack_hud")->sf_rect, pos);
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "block_hud")->sf_rect, pos);
    show_available_attack(scene, win);
}
