/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Texture Management
*/

#include "my_cgraph.h"

bool create_texture(textures_t **textures, const char *name, const char *path)
{
    textures_t *element = my_calloc(1, sizeof(*element));

    if (!element)
        return (false);
    element->name = name;
    element->sf_texture = sfTexture_createFromFile(path, NULL);
    if (!element->sf_texture)
        return (false);
    element->sf_sprite = sfSprite_create();
    element->sf_clock = sfClock_create();
    element->next = *textures;
    *textures = element;
    sfSprite_setTexture(element->sf_sprite, element->sf_texture, sfFalse);
    return (true);
}

textures_t *get_texture(textures_t *textures, const char *name)
{
    textures_t *element = textures;

    while (element != NULL) {
        if (my_strcmp(element->name, name) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}

void draw_textures(sfRenderWindow *win, textures_t *textures)
{
    textures_t *element = textures;

    while (element != NULL) {
        if (element->sf_sprite != NULL && element->visible)
            sfRenderWindow_drawSprite(win, element->sf_sprite, NULL);
        element = element->next;
    }
}

static bool destroy_first(textures_t **textures)
{
    textures_t *element = *textures;
    textures_t *next = NULL;

    if (!element)
        return (false);
    next = element->next;
    sfSprite_destroy(element->sf_sprite);
    sfTexture_destroy(element->sf_texture);
    free(element);
    *textures = next;
    return (true);
}

bool destroy_texture(textures_t **textures, const char *name)
{
    textures_t *element = *textures;
    textures_t *next = NULL;

    if (!element)
        return (false);
    if (my_strcmp(element->name, name) == 0 || element->next == NULL) {
        destroy_first(textures);
        return (true);
    }
    while (element->next != NULL) {
        if (my_strcmp(element->next->name, name) == 0) {
            next = element->next->next;
            sfSprite_destroy(element->next->sf_sprite);
            sfTexture_destroy(element->next->sf_texture);
            free(element->next);
            element->next = next;
            return (true);
        }
        element = element->next;
    }
    return (false);
}
