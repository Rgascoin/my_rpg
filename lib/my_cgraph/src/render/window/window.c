/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Window Management
*/

#include "my_cgraph.h"

sfRenderWindow *create_window(const char *title, int width, int height)
{
    sfVideoMode vmode = {width, height, 32};
    sfRenderWindow *win = NULL;

    win = sfRenderWindow_create(vmode, title, sfClose | sfResize, NULL);
    if (!win)
        return (NULL);
    sfRenderWindow_setFramerateLimit(win, 30);
    return (win);
}

bool destroy_window(sfRenderWindow *win)
{
    if (!win)
        return (false);
    sfRenderWindow_destroy(win);
    return (true);
}
