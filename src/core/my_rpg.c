/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** My RPG Game
*/

#include "my_rpg.h"
#include "my_init.h"
#include "my_game.h"
#include "my_render.h"
#include "my_destroy.h"

bool game_loop(win_t *win)
{
    if (!init_game(win)) {
        destroy_game(win);
        return (false);
    }
    while (sfRenderWindow_isOpen(win->sf_win)) {
        sfRenderWindow_clear(win->sf_win, sfBlack);
        event_handler(win);
        game_handler(win);
        render_handler(win);
        sfRenderWindow_display(win->sf_win);
    }
    destroy_game(win);
    return (true);
}
