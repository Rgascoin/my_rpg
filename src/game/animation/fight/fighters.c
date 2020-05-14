/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fighters
*/

#include "my_rpg.h"
#include "my_game.h"

bool player_standing(scenes_t *scene)
{
    textures_t *texture = get_texture(scene->textures, "player");

    if (!texture)
        return (false);
    if (texture->time >= 0.55) {
        animate_sprite(texture->sf_sprite, 39, 1);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
    return (true);
}

bool enemie_standing(scenes_t *scene, fighter_t *enemie)
{
    textures_t *texture = get_texture(scene->textures, enemie->texture);

    if (!texture)
        return (false);
    if (texture->time >= 0.75) {
        animate_sprite(texture->sf_sprite, 39, 1);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
    return (true);
}