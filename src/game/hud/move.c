/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move
*/

#include "my_rpg.h"

void move_inv(scenes_t *scene, float x, float y)
{
    sfVector2f c_i = sfSprite_getPosition(get_texture(scene->textures,
    "inv")->sf_sprite);
    sfVector2f c_b = sfSprite_getPosition(get_texture(scene->textures,
    "bandage")->sf_sprite);
    sfVector2f c_g = sfSprite_getPosition(get_texture(scene->textures,
    "glove")->sf_sprite);

    c_i.x += x;
    c_i.y += y;
    c_b.x += x;
    c_b.y += y;
    c_g.x += x;
    c_g.y += y;
    sfSprite_setPosition(get_texture(scene->textures, "inv")->sf_sprite, c_i);
    sfSprite_setPosition(get_texture(scene->textures, "bandage")->sf_sprite,
    c_b);
    sfSprite_setPosition(get_texture(scene->textures, "glove")->sf_sprite, c_g);
}

void move_hud(scenes_t *scene, float x, float y)
{
    sfVector2f i_hp = sfSprite_getPosition(get_texture(scene->textures,
    "hp")->sf_sprite);
    sfVector2f e_hp = sfSprite_getPosition(get_texture(scene->textures,
    "xp")->sf_sprite);
    sfVector2f c_hp = sfSprite_getPosition(get_texture(scene->textures,
    "coin")->sf_sprite);

    i_hp.x += x;
    i_hp.y += y;
    e_hp.x += x;
    e_hp.y += y;
    c_hp.x += x;
    c_hp.y += y;
    sfSprite_setPosition(get_texture(scene->textures, "hp")->sf_sprite, i_hp);
    sfSprite_setPosition(get_texture(scene->textures, "xp")->sf_sprite, e_hp);
    sfSprite_setPosition(get_texture(scene->textures, "coin")->sf_sprite, c_hp);
    move_inv(scene, x, y);
}