/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** heal
*/

#include "my_rpg.h"

void heal_player(win_t *win)
{
    if (win->game->player->gold < 55
    || win->game->player->pv == win->game->player->max_pv)
        return;
    win->game->player->gold -= 55;
    win->game->player->pv = win->game->player->max_pv;
    win->game->player->agility = win->game->player->max_agility;
    win->game->player->resistance = win->game->player->max_resistance;
    win->quest->hospital_count += 1;
}