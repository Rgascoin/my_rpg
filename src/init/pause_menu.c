/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_pause_menu.h"

bool init_pause_menu(win_t *win)
{
    create_scene(&win->scenes, "IN_PAUSE");
    if (!load_scene(get_scene(win->scenes, "IN_PAUSE"),
    "config/pause_menu.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_pause_menu_audio)
    || !load_error_button(win->scenes->buttons, asset_pause_menu_button)
    || !load_error_text(win->scenes->texts, asset_pause_menu_text)
    || !load_error_texture(win->scenes->textures, asset_pause_menu_texture))
        return (false);
    return (true);
}