/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_menu
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_option_menu.h"

bool init_option_menu(win_t *win)
{
    create_scene(&win->scenes, "IN_OPTION");
    if (!load_scene(get_scene(win->scenes, "IN_OPTION"),
    "config/option_menu.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_option_menu_audio)
    || !load_error_button(win->scenes->buttons, asset_option_menu_button)
    || !load_error_text(win->scenes->texts, asset_option_menu_text)
    || !load_error_texture(win->scenes->textures, asset_option_menu_texture))
        return (false);
    return (true);
}