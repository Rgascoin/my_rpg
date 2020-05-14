/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Collision Management
*/

#include "my_cgraph.h"

bool is_in_collision(sfRectangleShape *rect, sfCircleShape *circle)
{
    sfFloatRect rect_bound = sfRectangleShape_getGlobalBounds(rect);
    sfFloatRect circle_bound = sfCircleShape_getGlobalBounds(circle);

    return (sfFloatRect_intersects(&rect_bound, &circle_bound, NULL));
}
