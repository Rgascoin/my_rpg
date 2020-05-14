/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** gamestate
*/

#include "my_rpg.h"

void set_gamestate(game_t *game, gamestate_t gamestate)
{
    game->current_state = gamestate;
}

bool is_gamestate(game_t *game, gamestate_t gamestate)
{
    return (game->current_state == gamestate);
}

gamestate_t get_gamestate(game_t *game)
{
    return (game->current_state);
}