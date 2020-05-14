/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_inventory.h"

static bool place_inventory_load_check(scenes_t *scene, textures_t **textures)
{
    const char *name[] = {"glove", "bandage", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    return (true);
}

bool place_inv(scenes_t *scene)
{
    sfVector2f pos = {478, 573};
    textures_t *textures[] = {NULL, NULL, NULL};

    if (place_inventory_load_check(scene, textures) == false)
        return (false);
    sfSprite_setPosition(textures[0]->sf_sprite, pos);
    pos.x = 506;
    sfSprite_setPosition(textures[1]->sf_sprite, pos);
    return (true);
}

bool init_inventory(win_t *win)
{
    create_scene(&win->scenes, "IN_INVENTORY");
    if (!load_scene(get_scene(win->scenes, "IN_INVENTORY"),
    "config/inventory.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_inventory_audio)
    || !load_error_button(win->scenes->buttons, asset_inventory_button)
    || !load_error_text(win->scenes->texts, asset_inventory_text)
    || !load_error_texture(win->scenes->textures, asset_inventory_texture))
        return (false);
    return (true);
}