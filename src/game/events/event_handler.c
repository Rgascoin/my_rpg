/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_handler
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_game.h"

static bool event_process(win_t *win, sfEvent event)
{
    const char *name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, name);

    if (!scene)
        return (false);
    if (event.type == sfEvtKeyPressed)
        on_key_pressed(win);
    if (event.type == sfEvtMouseButtonReleased)
        on_button_clicked(win, scene);
    return (true);
}

void event_handler(win_t *win)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->sf_win, &event)) {
        if (event.type == sfEvtClosed)
            on_window_close(win);
        event_process(win, event);
    }
}
