/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** walk
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_game.h"

void move_right(win_t *win, scenes_t *scene)
{
    sfVector2f p_hp = sfText_getPosition(get_text(scene->texts,
    "player_hp")->sf_text);
    sfVector2f p_gold = sfText_getPosition(get_text(scene->texts,
    "player_gold")->sf_text);
    sfVector2f p_xp = sfText_getPosition(get_text(scene->texts,
    "player_xp")->sf_text);

    if (!colider_test(scene, win, 0, -5)) {
    win->game->player->pos.x += 5;
        p_hp.x += 5;
        p_gold.x += 5;
        p_xp.x += 5;
        move_hud(scene, 5, 0);
    }
    reset_visibility(scene);
    get_texture(scene->textures, "player_e")->visible = true;
    sfText_setPosition(get_text(scene->texts, "player_hp")->sf_text, p_hp);
    sfText_setPosition(get_text(scene->texts, "player_gold")->sf_text, p_gold);
    sfText_setPosition(get_text(scene->texts, "player_xp")->sf_text, p_xp);
}

void move_left(win_t *win, scenes_t *scene)
{
    sfVector2f p_hp = sfText_getPosition(get_text(scene->texts,
    "player_hp")->sf_text);
    sfVector2f p_gold = sfText_getPosition(get_text(scene->texts,
    "player_gold")->sf_text);
    sfVector2f p_xp = sfText_getPosition(get_text(scene->texts,
    "player_xp")->sf_text);

    if (!colider_test(scene, win, 0, 5)) {
        win->game->player->pos.x -= 5;
        p_hp.x -= 5;
        p_gold.x -= 5;
        p_xp.x -= 5;
        move_hud(scene, -5, 0);
    }
    reset_visibility(scene);
    get_texture(scene->textures, "player_w")->visible = true;
    sfText_setPosition(get_text(scene->texts, "player_hp")->sf_text, p_hp);
    sfText_setPosition(get_text(scene->texts, "player_gold")->sf_text, p_gold);
    sfText_setPosition(get_text(scene->texts, "player_xp")->sf_text, p_xp);
}

void move_up(win_t *win, scenes_t *scene)
{
    sfVector2f p_hp = sfText_getPosition(get_text(scene->texts,
    "player_hp")->sf_text);
    sfVector2f p_gold = sfText_getPosition(get_text(scene->texts,
    "player_gold")->sf_text);
    sfVector2f p_xp = sfText_getPosition(get_text(scene->texts,
    "player_xp")->sf_text);

    if (!colider_test(scene, win, 5, 0)) {
        p_hp.y -= 5;
        p_gold.y -= 5;
        p_xp.y -= 5;
        win->game->player->pos.y -= 5;
        move_hud(scene, 0, -5);
    }
    reset_visibility(scene);
    get_texture(scene->textures, "player_n")->visible = true;
    sfText_setPosition(get_text(scene->texts, "player_hp")->sf_text, p_hp);
    sfText_setPosition(get_text(scene->texts, "player_gold")->sf_text, p_gold);
    sfText_setPosition(get_text(scene->texts, "player_xp")->sf_text, p_xp);
}

void move_down(win_t *win, scenes_t *scene)
{
    sfVector2f p_hp = sfText_getPosition(get_text(scene->texts,
    "player_hp")->sf_text);
    sfVector2f p_gold = sfText_getPosition(get_text(scene->texts,
    "player_gold")->sf_text);
    sfVector2f p_xp = sfText_getPosition(get_text(scene->texts,
    "player_xp")->sf_text);

    if (!colider_test(scene, win, -5, 0)) {
        p_hp.y += 5;
        p_gold.y += 5;
        p_xp.y += 5;
        move_hud(scene, 0, 5);
        win->game->player->pos.y += 5;
    }
    reset_visibility(scene);
    get_texture(scene->textures, "player_s")->visible = true;
    sfText_setPosition(get_text(scene->texts, "player_hp")->sf_text, p_hp);
    sfText_setPosition(get_text(scene->texts, "player_gold")->sf_text, p_gold);
    sfText_setPosition(get_text(scene->texts, "player_xp")->sf_text, p_xp);
}

void move_player(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    hide_animation(win);
    get_texture(scene->textures, "player_idle")->visible = false;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_right(win, scene);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_left(win, scene);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move_up(win, scene);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_down(win, scene);
    }
}