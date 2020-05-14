/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Animation Management
*/

#include "my_cgraph.h"

void animate_sprite(sfSprite *sprite, int offset, int max)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.width = offset;
    if (rect.left >= max)
        rect.left = 0;
    else
        rect.left += offset;
    sfSprite_setTextureRect(sprite, rect);
}
