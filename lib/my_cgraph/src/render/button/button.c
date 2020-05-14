/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Button Management
*/

#include "my_cgraph.h"

bool create_button(buttons_t **buttons, const char *name)
{
    buttons_t *element = my_calloc(1, sizeof(*element));

    if (!element)
        return (false);
    element->name = name;
    element->sf_rect = sfRectangleShape_create();
    element->next = *buttons;
    *buttons = element;
    return (true);
}

buttons_t *get_button(buttons_t *buttons, const char *name)
{
    buttons_t *element = buttons;

    while (element != NULL) {
        if (my_strcmp(element->name, name) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}

void draw_buttons(sfRenderWindow *win, buttons_t *buttons)
{
    buttons_t *element = buttons;

    while (element != NULL) {
        if (element->sf_rect != NULL)
            sfRenderWindow_drawRectangleShape(win, element->sf_rect, NULL);
        if (element->text != NULL)
            sfRenderWindow_drawText(win, element->text->sf_text, NULL);
        element = element->next;
    }
}

static bool destroy_first(buttons_t **buttons)
{
    buttons_t *element = *buttons;
    buttons_t *next = NULL;

    if (!element)
        return (false);
    next = element->next;
    sfRectangleShape_destroy(element->sf_rect);
    free(element);
    *buttons = next;
    return (true);
}

bool destroy_button(buttons_t **buttons, const char *name)
{
    buttons_t *element = *buttons;
    buttons_t *next = NULL;

    if (!element)
        return (false);
    if (my_strcmp(element->name, name) == 0 || element->next == NULL) {
        destroy_first(buttons);
        return (true);
    }
    while (element->next != NULL) {
        if (my_strcmp(element->next->name, name) == 0) {
            next = element->next->next;
            sfRectangleShape_destroy(element->next->sf_rect);
            free(element->next);
            element->next = next;
            return (true);
        }
        element = element->next;
    }
    return (false);
}
