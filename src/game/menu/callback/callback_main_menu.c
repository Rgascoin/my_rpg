/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my_rpg.h"
#include "my_game.h"

void launch_game(win_t *win)
{
    set_gamestate(win->game, IN_GAME);
    my_printf("PLAY\n");
}

void main_howtoplay_button(win_t *win)
{
    set_gamestate(win->game, IN_HOWTOPLAY);
    my_printf("HOW TO PLAY\n");
}

void main_option_button(win_t *win)
{
    set_gamestate(win->game, IN_OPTION);
    my_printf("OPTIONS\n");
}