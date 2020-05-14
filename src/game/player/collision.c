/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** collision
*/

#include "my_rpg.h"

bool colider_test(scenes_t *scene, win_t *win, int y, int x)
{
    sfFloatRect player = sfSprite_getGlobalBounds(get_texture(scene->textures,
    "player_s")->sf_sprite);
    sfFloatRect wall = sfRectangleShape_getGlobalBounds(
    get_button(scene->buttons, "A")->sf_rect);
    char name[2] = {'\0', '\0'};

    name[0] = 'A';
    name[1] = '\0';
    (void)win;
    player.top -= y;
    player.left -= x;
    while (name[0] != '\\') {
        wall = sfRectangleShape_getGlobalBounds(
        get_button(scene->buttons, name)->sf_rect);
        name[0] += 1;
        if (sfFloatRect_intersects(&player, &wall, NULL))
            return (true);
    }
    return (false);
}