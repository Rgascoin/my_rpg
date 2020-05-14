/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_interaction
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_game.h"

void quest_fight(win_t *win, textures_t *texture)
{
    if (win->quest->active == true
    && win->quest->current_quest == WIN_3_TIMES) {
        if (win->game->player->win == 3) {
            texture->visible = false;
            win->quest->active = false;
            win->game->player->gold += 100;
        }
    }
}

void quest_heal(win_t *win, textures_t *texture)
{
    if (win->quest->active == true
    && win->quest->current_quest == HEAL_3_TIMES) {
        if (win->quest->hospital_count == 3) {
            texture->visible = false;
            win->quest->active = false;
            win->game->player->gold += 100;
        }
    }
}

bool player_quest(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    textures_t *texture = NULL;

    if (!scene || !(texture = get_texture(scene->textures, quest_name(win))))
        return (false);
    if (win->game->player->pos.x >= 450 && win->game->player->pos.x <= 500
    && win->game->player->pos.y >= 225 && win->game->player->pos.y <= 275) {
        texture->visible = true;
    } else
        texture->visible = false;
    if (win->game->player->pos.x >= 450 && win->game->player->pos.x <= 500
    && win->game->player->pos.y >= 225 && win->game->player->pos.y <= 275
    && win->quest->active == false && sfKeyboard_isKeyPressed(sfKeyE)) {
        texture->visible = false;
        win->quest->active = true;
        win->quest->current_quest += 1;
    }
    quest_status(win, texture);
    return (true);
}