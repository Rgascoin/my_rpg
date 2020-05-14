/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Texture Utils Management
*/

#include "my_cgraph.h"

bool init_texture(textures_t *texture, sfVector2f pos, bool visible,
    const char *tag)
{
    if (!texture)
        return (false);
    texture->visible = visible;
    texture->tag = tag;
    sfSprite_setPosition(texture->sf_sprite, pos);
    return (true);
}

bool set_texture_tag(textures_t *texture, const char *tag)
{
    if (!texture)
        return (false);
    texture->tag = tag;
    return (true);
}

bool set_texture_visible(textures_t *texture, bool visible)
{
    if (!texture)
        return (false);
    texture->visible = visible;
    return (true);
}

int count_textures(textures_t *textures)
{
    int count = 0;
    textures_t *element = textures;

    while (element != NULL) {
        count++;
        element = element->next;
    }
    return (count);
}
