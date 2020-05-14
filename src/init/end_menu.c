/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** End Menu Management
*/

#include "my_rpg.h"
#include "my_yml.h"

bool init_end_menu(win_t *win)
{
    create_scene(&win->scenes, "POST_GAME");
    if (!load_scene(get_scene(win->scenes, "POST_GAME"),
    "config/postgame_menu.rll"))
        return (false);
    return (true);
}
