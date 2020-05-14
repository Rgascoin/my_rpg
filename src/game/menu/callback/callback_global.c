/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_callback
*/

#include "my_rpg.h"
#include "my_game.h"

void nothing(win_t *win)
{
    (void)win;
    return;
}

bool quit_game(win_t *win)
{
    sfRenderWindow_close(win->sf_win);
    return (true);
}

void back_to_menu(win_t *win)
{
    set_gamestate(win->game, PRE_GAME);
}