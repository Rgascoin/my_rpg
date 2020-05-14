/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hud
*/

#include "my_rpg.h"

static void resize_hud(scenes_t *scene)
{
    sfVector2f scale = {0.3, 0.3};

    sfText_setScale(get_text(scene->texts, "player_hp")->sf_text, scale);
    sfText_setScale(get_text(scene->texts, "player_gold")->sf_text, scale);
    sfText_setScale(get_text(scene->texts, "player_xp")->sf_text, scale);
    scale.x = 0.15;
    scale.y = 0.15;
    sfSprite_setScale(get_texture(scene->textures, "hp")->sf_sprite, scale);
    scale.x = 0.1;
    scale.y = 0.1;
    sfSprite_setScale(get_texture(scene->textures, "coin")->sf_sprite, scale);
    sfSprite_setScale(get_texture(scene->textures, "xp")->sf_sprite, scale);
}

static void place_hud(scenes_t *scene)
{
    sfVector2f pos = {135, 215};

    sfSprite_setPosition(get_texture(scene->textures, "hp")->sf_sprite, pos);
    pos.y = 275;
    pos.x = 140;
    sfSprite_setPosition(get_texture(scene->textures, "coin")->sf_sprite, pos);
    pos.y = 245;
    pos.x = 134;
    sfSprite_setPosition(get_texture(scene->textures, "xp")->sf_sprite, pos);
    pos.y = 250;
    pos.x = 760;
    sfSprite_setPosition(get_texture(scene->textures, "arena_buble")->sf_sprite,
    pos);
    pos.y = 395;
    pos.x = 690;
    sfSprite_setPosition(get_texture(scene->textures, "rest_room")->sf_sprite,
    pos);
}

bool init_hud(scenes_t *scene)
{
    resize_hud(scene);
    place_hud(scene);
    return (true);
}