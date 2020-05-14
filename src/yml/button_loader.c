/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Button Loader Management
*/

#include "my_rpg.h"

static bool load_button(buttons_t **buttons, textures_t **textures,
    config_t *button)
{
    char *name = get_field("name", button->data);
    char *texture = get_field("texture", button->data);
    void *callback = get_function("callback", button->data);
    sfVector2f pos = {my_atoi(get_field("pos.x", button->data)),
        my_atoi(get_field("pos.y", button->data))};
    sfVector2f size = {my_atoi(get_field("size.x", button->data)),
        my_atoi(get_field("size.y", button->data))};

    if (!name || !texture || !callback)
        return (false);
    create_button(buttons, name);
    if (!get_button(*buttons, name))
        return (false);
    init_button(get_button(*buttons, name), pos, size, callback);
    set_button_texture(get_button(*buttons, name),
        get_texture(*textures, texture));
    return (true);
}

bool load_buttons(buttons_t **buttons, textures_t **textures, const char *path)
{
    bool status = true;
    config_t *config = NULL;
    config_t *element = NULL;

    if (!load_config(&config, path))
        return (false);
    element = config;
    while (element != NULL) {
        if (my_strcmp(element->name, "button") == 0)
            status = load_button(buttons, textures, element);
        if (!status)
            return (false);
        element = element->next;
    }
    return (true);
}
