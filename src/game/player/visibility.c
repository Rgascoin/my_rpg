/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** visibility
*/

#include "my_rpg.h"

void reset_visibility(scenes_t *scene)
{
    get_texture(scene->textures, "player_n")->visible = false;
    get_texture(scene->textures, "player_e")->visible = false;
    get_texture(scene->textures, "player_w")->visible = false;
    get_texture(scene->textures, "player_s")->visible = false;
}