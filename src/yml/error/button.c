/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button
*/

#include "my_rpg.h"

bool button_error_run(buttons_t *button, const char **assets, buttons_t *tmp,
int i)
{
    for (tmp = button; tmp != NULL; tmp = tmp->next) {
        if ((get_button(tmp, assets[i])) != NULL)
            break;
    }
    if (tmp == NULL)
        return (false);
    return (true);
}

bool load_error_button(buttons_t *button, const char **assets)
{
    buttons_t *tmp = NULL;

    for (int i = 0; assets[i] != NULL; i++) {
        if (button_error_run(button, assets, tmp, i) == false) {
            my_printf("Invalid config file (button).\n");
            return (false);
        }
    }
    return (true);
}