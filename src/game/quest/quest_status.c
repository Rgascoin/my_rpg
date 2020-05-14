/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_status
*/

#include "my_rpg.h"
#include "my_game.h"

char *quest_name(win_t *win)
{
    if (win->quest->current_quest == WIN_3_TIMES && win->quest->active == true)
        return ("quest_buble_01");
    if (win->quest->current_quest == HEAL_3_TIMES && win->quest->active == true)
        return ("quest_buble_02");
    if (win->quest->active == false)
        return ("quest_ask");
    return ("quest_empty");
}

void quest_status(win_t *win, textures_t *texture)
{
    quest_fight(win, texture);
    quest_heal(win, texture);
}