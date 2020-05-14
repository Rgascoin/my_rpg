/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game
*/

#include "my_rpg.h"
#include "my_game.h"
#include "my_init.h"

bool init_game(win_t *win)
{
    set_gamestate(win->game, PRE_GAME);
    if (!init_main_menu(win) || !init_core(win) || !init_option_menu(win)
    || !init_howtoplay_menu(win) || !init_fight(win) || !init_inventory(win)
    || !init_level_up(win) || !init_pause_menu(win) || !init_end_menu(win))
        return (false);
    return (true);
}
