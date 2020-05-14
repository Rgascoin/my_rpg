/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_loop
*/

#include "my_rpg.h"
#include "my_game.h"

bool in_game(win_t *win)
{
    player_movements(win);
    animate_player(win);
    camera_handler(win);
    update_hud(win);
    update_level(win);
    animate_arena(win);
    animate_rest(win);
    animate_rest_bubble(win);
    player_quest(win);
    return (true);
}