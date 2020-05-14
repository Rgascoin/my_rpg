/*
** EPITECH PROJECT, 2020
** RPG_NORM_MDR
** File description:
** event_window
*/

#include "my_rpg.h"

void on_window_close(win_t *win)
{
    sfRenderWindow_close(win->sf_win);
}