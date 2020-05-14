/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** moves
*/

#include "my_rpg.h"

void animate_south(scenes_t *scene)
{
    textures_t *texture = get_texture(scene->textures, "player_s");

    if (!texture)
        return;
    if (texture->time >= 0.25) {
        animate_sprite(texture->sf_sprite, 47, 90);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
}

void animate_east(scenes_t *scene)
{
    textures_t *texture = get_texture(scene->textures, "player_e");

    if (!texture)
        return;
    if (texture->time >= 0.25) {
        animate_sprite(texture->sf_sprite, 47, 90);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
}

void animate_west(scenes_t *scene)
{
    textures_t *texture = get_texture(scene->textures, "player_w");

    if (!texture)
        return;
    if (texture->time >= 0.25) {
        animate_sprite(texture->sf_sprite, 46, 90);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
}

void animate_north(scenes_t *scene)
{
    textures_t *texture = get_texture(scene->textures, "player_n");

    if (!texture)
        return;
    if (texture->time >= 0.25) {
        animate_sprite(texture->sf_sprite, 46, 90);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
}