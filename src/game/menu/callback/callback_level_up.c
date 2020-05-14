/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** callback_level_up
*/

#include "my_rpg.h"

void up_agi(win_t *win)
{
    if (win->game->player->skill <= 0)
        return;
    win->game->player->max_agility += 1;
    win->game->player->skill -= 1;
}

void up_str(win_t *win)
{
    if (win->game->player->skill <= 0)
        return;
    win->game->player->max_strength += 1;
    win->game->player->skill -= 1;
}

void up_resi(win_t *win)
{
    if (win->game->player->skill <= 0)
        return;
    win->game->player->max_resistance += 1;
    win->game->player->skill -= 1;
}