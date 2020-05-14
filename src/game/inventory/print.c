/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** print
*/

#include "my_rpg.h"
#include "my_gamestate.h"

void print_player_data(scenes_t *scene, win_t *win)
{
    sfText_setString(get_text(scene->texts, "name")->sf_text,
    my_strcat(my_strcat(win->game->player->name, " LV : "),
    my_itoa(win->game->player->level)));
    sfText_setString(get_text(scene->texts, "pv")->sf_text,
    my_strcat("PV : ", my_strcat(my_itoa(win->game->player->pv),
    my_strcat("/", my_itoa(win->game->player->max_pv)))));
    sfText_setString(get_text(scene->texts, "strength")->sf_text,
    my_strcat("Strength : ", my_strcat(my_itoa(win->game->player->strength),
    my_strcat("/", my_itoa(win->game->player->max_strength)))));
    sfText_setString(get_text(scene->texts, "agility")->sf_text,
    my_strcat("Agility : ", my_strcat(my_itoa(win->game->player->agility),
    my_strcat("/", my_itoa(win->game->player->max_agility)))));
    sfText_setString(get_text(scene->texts, "resistance")->sf_text,
    my_strcat("Resistance : ", my_strcat(my_itoa(win->game->player->resistance),
    my_strcat("/", my_itoa(win->game->player->max_resistance)))));
}

void print_stats(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    sfVector2f scale = {0.4, 0.4};

    print_player_data(scene, win);
    sfText_setString(get_text(scene->texts, "desc_punch")->sf_text,
    "A powerfull and devastating hit,\n\ndamaged base on your Strengh");
    sfText_setString(get_text(scene->texts, "desc_kick")->sf_text,
    "A kickly and smooth move,\n\ndamaged base on your Agility");
    sfText_setString(get_text(scene->texts, "desc_upercut")->sf_text,
    "REQ Str 5,\n\ndamaged base on your Stregth \n\nand ignore Oponent \
    resistance");
    sfText_setScale(get_text(scene->texts, "desc_punch")->sf_text, scale);
    sfText_setScale(get_text(scene->texts, "desc_kick")->sf_text, scale);
    sfText_setScale(get_text(scene->texts, "desc_upercut")->sf_text, scale);
}