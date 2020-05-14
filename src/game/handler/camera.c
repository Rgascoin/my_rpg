/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** camera
*/

#include "my_rpg.h"

bool camera_handler(win_t *win)
{
    sfVector2f pos = win->game->player->pos;

    pos.x += 32;
    pos.y += 50;
    sfView_setCenter(win->game->camera->player, pos);
    sfRenderWindow_setView(win->sf_win, win->game->camera->player);
    return (true);
}