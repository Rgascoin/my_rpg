/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** level_update
*/

#include "my_rpg.h"
#include "my_level.h"
#include "my_game.h"

void update_level(win_t *win)
{
    int save = xp_ranking[win->game->player->level];

    if (win->game->player->xp >= xp_ranking[win->game->player->level]) {
        set_gamestate(win->game, IN_LEVELUP);
        save = win->game->player->xp - xp_ranking[win->game->player->level];
        win->game->player->xp = 0 + save;
        win->game->player->skill += win->game->player->level;
    }
}