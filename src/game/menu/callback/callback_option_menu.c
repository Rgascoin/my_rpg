/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** callback_option_menu
*/

#include "my_rpg.h"

void option_display_map(win_t *win)
{
    if (win->show_map == true)
        win->show_map = false;
    else
        win->show_map = true;
}

void option_sound(win_t *win)
{
    scenes_t *scene = get_scene(win->scenes, "IN_GAME");

    if (!scene)
        return ;
    if (win->sound_status == true) {
        win->sound_status = false;
        sfMusic_pause(get_audio(scene->audios, "bracket")->sf_music);
    } else {
        win->sound_status = true;
        sfMusic_play(get_audio(scene->audios, "bracket")->sf_music);
    }
}