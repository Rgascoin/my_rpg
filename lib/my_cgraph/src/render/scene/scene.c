/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Scene Management
*/

#include "my_cgraph.h"

bool create_scene(scenes_t **scenes, const char *name)
{
    scenes_t *element = my_calloc(1, sizeof(*element));

    if (!element)
        return (false);
    element->name = name;
    element->next = *scenes;
    *scenes = element;
    return (true);
}

scenes_t *get_scene(scenes_t *scenes, const char *name)
{
    scenes_t *element = scenes;

    while (element != NULL) {
        if (my_strcmp(element->name, name) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}

void draw_scene(sfRenderWindow *win, scenes_t *scene)
{
    scenes_t *element = scene;

    if (!element)
        return;
    draw_textures(win, element->textures);
    draw_texts(win, element->texts);
    draw_buttons(win, element->buttons);
}

static bool destroy_first(scenes_t **scenes)
{
    scenes_t *element = *scenes;
    scenes_t *next = NULL;

    if (!element)
        return (false);
    next = element->next;
    free(element);
    *scenes = next;
    return (true);
}

bool destroy_scene(scenes_t **scenes, const char *name)
{
    scenes_t *element = *scenes;
    scenes_t *next = NULL;

    if (!element)
        return (false);
    if (my_strcmp(element->name, name) == 0 || element->next == NULL) {
        destroy_first(scenes);
        return (true);
    }
    while (element->next != NULL) {
        if (my_strcmp(element->next->name, name) == 0) {
            next = element->next->next;
            free(element->next);
            element->next = next;
            return (true);
        }
        element = element->next;
    }
    return (false);
}
