/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Key Pressed Event Management
*/

#include "my_rpg.h"
#include "my_game.h"

void open_inv(win_t *win)
{
    set_gamestate(win->game, IN_INVENTORY);
    print_stats(win);
    move_spell(win);
    move_cross(win);
}