/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** level_up
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_level.h"

bool init_level_up(win_t *win)
{
    create_scene(&win->scenes, "IN_LEVELUP");
    if (!load_scene(get_scene(win->scenes, "IN_LEVELUP"),
    "config/levelup.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_level_audio)
    || !load_error_button(win->scenes->buttons, asset_level_button)
    || !load_error_text(win->scenes->texts, asset_level_text)
    || !load_error_texture(win->scenes->textures, asset_level_texture))
        return (false);
    return (true);
}