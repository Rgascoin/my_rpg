/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_fight.h"

static bool load_fighters(scenes_t *scene, textures_t **textures)
{
    char *name[] = {"player", "enemie1", "enemie2", "enemie3", NULL};

    for (int i = 0; name[i] != NULL; i++) {
        textures[i] = get_texture(scene->textures, name[i]);
        if (textures[i] == NULL)
            return (false);
    }
    return (true);
}

static bool place_fighters(scenes_t *scene)
{
    sfVector2f p_pos = {340, 200};
    sfVector2f e_pos = {840, 200};
    sfVector2f p_scale = {3, 3};
    sfVector2f e_scale = {3, 3};
    textures_t *textures[] = {NULL, NULL, NULL, NULL, NULL};

    if (load_fighters(scene, textures) == false)
        return (false);
    sfSprite_setScale(textures[0]->sf_sprite, p_scale);
    sfSprite_setPosition(textures[0]->sf_sprite, p_pos);
    for (int i = 1; i < 4; i++) {
        sfSprite_setScale(textures[i]->sf_sprite, e_scale);
        sfSprite_setPosition(textures[i]->sf_sprite, e_pos);
    }
    e_pos.x = 780;
    e_pos.y = 500;
    sfSprite_setPosition(get_texture(scene->textures, "cross")->sf_sprite,
    e_pos);
    return (true);
}

bool init_fight(win_t *win)
{
    create_scene(&win->scenes, "IN_FIGHT");
    if (!load_scene(get_scene(win->scenes, "IN_FIGHT"), "config/fight.rll"))
        return (false);
    if (!load_error_audio(win->scenes->audios, asset_fight_audio)
    || !load_error_button(win->scenes->buttons, asset_fight_button)
    || !load_error_text(win->scenes->texts, asset_fight_text)
    || !load_error_texture(win->scenes->textures, asset_fight_texture))
        return (false);
    if (place_fighters(get_scene(win->scenes, "IN_FIGHT")) == false)
        return (false);
    return (true);
}