/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_keyboard
*/

#include "my_rpg.h"
#include "my_game.h"

void is_in_inventory(win_t *win)
{
    if (is_gamestate(win->game, IN_INVENTORY)) {
        if (sfKeyboard_isKeyPressed(sfKeyI)
        || sfKeyboard_isKeyPressed(sfKeyEscape))
            set_gamestate(win->game, IN_GAME);
    }
}

void on_key_pressed(win_t *win)
{
    if (is_gamestate(win->game, IN_GAME)) {
        move_player(win);
        if (sfKeyboard_isKeyPressed(sfKeyE)
        && (win->game->player->pos.y >= 300 && win->game->player->pos.y <= 310)
        && (win->game->player->pos.x >= 770 && win->game->player->pos.x <= 820))
            start_fight(win);
        if (sfKeyboard_isKeyPressed(sfKeyE)
        && (win->game->player->pos.y >= 455 && win->game->player->pos.y <= 460)
        && (win->game->player->pos.x >= 695 && win->game->player->pos.x <= 765))
            heal_player(win);
        if (sfKeyboard_isKeyPressed(sfKeyI)) {
            open_inv(win);
            return ;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            set_gamestate(win->game, IN_PAUSE);
    } else if (is_gamestate(win->game, IN_PAUSE)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            set_gamestate(win->game, IN_GAME);
    }
    is_in_inventory(win);
}