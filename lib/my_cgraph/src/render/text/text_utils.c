/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Text Utils Management
*/

#include "my_cgraph.h"

bool init_text(texts_t *text, sfVector2f pos, const char *str)
{
    if (!text)
        return (false);
    sfText_setPosition(text->sf_text, pos);
    sfText_setString(text->sf_text, str);
    return (true);
}

int count_texts(texts_t *texts)
{
    int count = 0;
    texts_t *element = texts;

    while (element != NULL) {
        count++;
        element = element->next;
    }
    return (count);
}
