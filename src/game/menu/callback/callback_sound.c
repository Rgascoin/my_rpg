/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** callback_sound
*/

#include "my_rpg.h"

void sound_option(win_t *win)
{
    static bool sound_status = true;

    (void)win;
    if (sound_status == true) {
        sound_status = false;
    } else if (sound_status == false) {
        sound_status = true;
    }
}