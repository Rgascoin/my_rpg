/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Texture Loader Management
*/

#include "my_rpg.h"

static bool load_texture(textures_t **textures, config_t *texture)
{
    char *name = get_field("name", texture->data);
    char *path = get_field("path", texture->data);
    char *visibility = get_field("visibility", texture->data);
    char *tag = get_field("tag", texture->data);
    sfVector2f pos = {my_atoi(get_field("pos.x", texture->data)),
        my_atoi(get_field("pos.y", texture->data))};

    if (!name || !path || !visibility)
        return (false);
    create_texture(textures, name, path);
    if (!get_texture(*textures, name))
        return (false);
    init_texture(get_texture(*textures, name), pos, my_atob(visibility), tag);
    return (true);
}

bool load_textures(textures_t **textures, const char *path)
{
    bool status = true;
    config_t *config = NULL;
    config_t *element = NULL;

    if (!load_config(&config, path))
        return (false);
    element = config;
    while (element != NULL) {
        if (my_strcmp(element->name, "texture") == 0)
            status = load_texture(textures, element);
        if (!status)
            return (false);
        element = element->next;
    }
    return (true);
}
