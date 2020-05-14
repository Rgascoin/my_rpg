/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "my_rpg.h"
#include "my_game.h"

void back_to_game(win_t *win)
{
    int malus = (rand() % 10) + 1;

    set_gamestate(win->game, IN_GAME);
    if (win->game->fight->player_1->pv > 0)
        win->game->player->pv = win->game->fight->player_1->pv;
    else
        win->game->player->pv = 1;
    if (win->game->player->win >= 20 && (malus >= 7 && malus <= 10)) {
        (malus == 7 || malus == 8) ? win->game->player->strength -= 1: 0;
        (malus == 9 || malus == 10) ? win->game->player->agility -= 1: 0;
    }
}

void end_levelup(win_t *win)
{
    win->game->player->max_pv += 5;
    win->game->player->pv = win->game->player->max_pv;
    win->game->player->agility = win->game->player->max_agility;
    win->game->player->resistance = win->game->player->max_resistance;
    win->game->player->strength = win->game->player->max_strength;
    win->game->player->level += 1;
    set_gamestate(win->game, IN_GAME);
}