/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** camera
*/

#include "my_rpg.h"

static bool create_camera(win_t *win)
{
    camera_t *camera = my_calloc(1, sizeof(*camera));
    sfFloatRect player = {400, 400, 400, 400};
    sfFloatRect vp_player = {0, 0, 1, 1};
    sfFloatRect vp_map = {0.75f, 0, 0.25f, 0.25f};

    camera->player = sfView_createFromRect(player);
    camera->map = sfView_create();
    sfView_setViewport(camera->player, vp_player);
    sfView_setViewport(camera->map, vp_map);
    win->game->camera = camera;
    return (true);
}

bool init_camera(win_t *win)
{
    if (create_camera(win) == false)
        return (false);
    return (true);
}