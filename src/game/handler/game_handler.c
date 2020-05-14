/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_handler
*/

#include "my_rpg.h"
#include "my_game.h"

bool game_handler(win_t *win)
{
    gamestate_t gamestate = get_gamestate(win->game);
    bool (*tab[]) (win_t *win) = {&animate_background, &in_game, &in_fight,
    &animate_background, &in_level_up, &animate_background,
    &animate_background, &animate_background};

    if (is_gamestate(win->game, IN_INVENTORY)
    || is_gamestate(win->game, POST_GAME))
        return (true);
    if (tab[gamestate] (win) == false)
        return (false);
    return (true);
}