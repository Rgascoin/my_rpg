/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_button
*/

#include "my_rpg.h"

void on_button_clicked(win_t *win, scenes_t *scene)
{
    buttons_t *element = NULL;

    if (!scene)
        return;
    element = scene->buttons;
    while (element != NULL) {
        if (button_is_clicked(win->sf_win, element))
            (element->callback != NULL) ? element->callback(win, element) : 0;
        element = element->next;
    }
}