/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loader
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_enemie.h"

void back_fight(win_t *win)
{
    const char *name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, name);
    sfVector2f pos = {-200, -100};

    get_texture(scene->textures, "cross")->visible = false;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "punch_hud")->sf_rect, pos);
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "kick_hud")->sf_rect, pos);
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "back_hud")->sf_rect, pos);
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "upercut_hud")->sf_rect, pos);
    pos.y = 600;
    pos.x = 330;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "block_hud")->sf_rect, pos);
    pos.x = 830;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "attack_hud")->sf_rect, pos);
}

void move_string(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    sfVector2f pos = {50, 300};

    sfText_setPosition(get_text(scene->texts, "player_hp")->sf_text, pos);
    pos.x = 1050;
    sfText_setPosition(get_text(scene->texts, "enemie_hp")->sf_text, pos);
    pos.y = 100;
    pos.x = 300;
    sfText_setPosition(get_text(scene->texts, "player_name")->sf_text, pos);
    pos.x = 750;
    sfText_setPosition(get_text(scene->texts, "enemie_name")->sf_text, pos);
    pos.y = -200;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "continue_hud")->sf_rect, pos);
}

void set_string(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    sfText_setString(get_text(scene->texts, "player_attack")->sf_text,
    "waiting");
    sfText_setString(get_text(scene->texts, "enemie_attack")->sf_text,
    "waiting");
}

void set_enemie_texture(win_t *win, fighter_t *enemie)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    char *type = (char *)enemie_type[rand() % (3)];

    (void)enemie_name;
    get_texture(scene->textures, "enemie1")->visible = false;
    get_texture(scene->textures, "enemie2")->visible = false;
    get_texture(scene->textures, "enemie3")->visible = false;
    get_texture(scene->textures, type)->visible = true;
    enemie->texture = type;
    win->game->fight->player_1->texture = "charle";
}