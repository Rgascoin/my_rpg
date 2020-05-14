/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** howtoplay
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_htp.h"

bool init_howtoplay_menu(win_t *win)
{
    create_scene(&win->scenes, "IN_HOWTOPLAY");
    if (!load_scene(get_scene(win->scenes, "IN_HOWTOPLAY"),
    "config/howtoplay_menu.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_howtoplay_audio)
    || !load_error_button(win->scenes->buttons, asset_howtoplay_button)
    || !load_error_text(win->scenes->texts, asset_howtoplay_text)
    || !load_error_texture(win->scenes->textures, asset_howtoplay_texture))
        return (false);
    return (true);
}