/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Text Management
*/

#include "my_cgraph.h"

bool create_text(texts_t **texts, const char *name, const char *font)
{
    texts_t *element = my_calloc(1, sizeof(*element));

    if (!element || !font)
        return (false);
    element->name = name;
    element->sf_font = sfFont_createFromFile(font);
    if (!element->sf_font)
        return (false);
    element->sf_text = sfText_create();
    element->next = *texts;
    *texts = element;
    sfText_setFont(element->sf_text, element->sf_font);
    return (true);
}

texts_t *get_text(texts_t *texts, const char *name)
{
    texts_t *element = texts;

    while (element != NULL) {
        if (my_strcmp(element->name, name) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}

void draw_texts(sfRenderWindow *win, texts_t *texts)
{
    texts_t *element = texts;

    while (element != NULL) {
        if (element->sf_text != NULL)
            sfRenderWindow_drawText(win, element->sf_text, NULL);
        element = element->next;
    }
}

static bool destroy_first(texts_t **texts)
{
    texts_t *element = *texts;
    texts_t *next = NULL;

    if (!element)
        return (false);
    next = element->next;
    sfFont_destroy(element->sf_font);
    sfText_destroy(element->sf_text);
    free(element);
    *texts = next;
    return (true);
}

bool destroy_text(texts_t **texts, const char *name)
{
    texts_t *element = *texts;
    texts_t *next = NULL;

    if (!element)
        return (false);
    if (my_strcmp(element->name, name) == 0 || element->next == NULL) {
        destroy_first(texts);
        return (true);
    }
    while (element->next != NULL) {
        if (my_strcmp(element->next->name, name) == 0) {
            next = element->next->next;
            sfFont_destroy(element->next->sf_font);
            sfText_destroy(element->next->sf_text);
            free(element->next);
            element->next = next;
            return (true);
        }
        element = element->next;
    }
    return (false);
}
