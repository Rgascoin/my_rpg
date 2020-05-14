/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_main_menu.h"

bool init_main_menu(win_t *win)
{
    create_scene(&win->scenes, "PRE_GAME");
    if (!load_scene(get_scene(win->scenes, "PRE_GAME"),
    "config/main_menu.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_main_menu_audio)
    || !load_error_button(win->scenes->buttons, asset_main_menu_button)
    || !load_error_text(win->scenes->texts, asset_main_menu_text)
    || !load_error_texture(win->scenes->textures, asset_main_menu_texture))
        return (false);
    return (true);
}