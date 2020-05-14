/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text
*/

#include "my_rpg.h"

bool text_error_run(texts_t *text, const char **assets, texts_t *tmp, int i)
{
    for (tmp = text; tmp != NULL; tmp = tmp->next) {
        if ((get_text(tmp, assets[i])) != NULL)
            break;
    }
    if (tmp == NULL)
        return (false);
    return (true);
}

bool load_error_text(texts_t *text, const char **assets)
{
    texts_t *tmp = NULL;

    for (int i = 0; assets[i] != NULL; i++) {
        if (text_error_run(text, assets, tmp, i) == false) {
            my_printf("Invalid config file (text).\n");
            return (false);
        }
    }
    return (true);
}