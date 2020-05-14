/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "my_rpg.h"
#include "my_game.h"
#include "my_gamestate.h"

void player_punch_forward(scenes_t *scene, int status,
textures_t *texture, sfVector2f pos)
{
    if (status == 1)
        pos.x += 20;
    else
        pos.x -= 20;
    if (!texture)
        return;
    if (texture->time >= 0.05) {
        sfSprite_setPosition(get_texture(scene->textures, "player")->sf_sprite,
        pos);
        sfClock_restart(texture->sf_clock);
    }
    texture->time = sfTime_asSeconds(sfClock_getElapsedTime(texture->sf_clock));
}

bool player_punch_backward(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    textures_t *texture = NULL;
    sfVector2f actual = {0};

    if (!scene || (texture = get_texture(scene->textures, "player")) == NULL)
        return (false);
    actual = sfSprite_getPosition(texture->sf_sprite);
    if (actual.x != 340)
        player_punch_forward(scene, 0, texture, actual);
    else {
        if (win->game->fight->player_2->pv > 0)
            enemie_attack(win);
        win->game->fight->player_1->attacked = 0;
        win->game->fight->player_1->resistance =
        win->game->fight->player_1->max_resistance;
        (win->quest->current_quest == END) ?
        win->game->fight->player_1->pv += 5 : 0;
    }
    return (true);
}

bool animate_player_punch(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    textures_t *texture = NULL;
    sfVector2f actual = {0};

    if (!scene || (texture = get_texture(scene->textures, "player")) == NULL)
        return (false);
    actual = sfSprite_getPosition(texture->sf_sprite);
    if (actual.x != 440)
        player_punch_forward(scene, 1, texture, actual);
    else
        win->game->fight->player_1->attacked = 3;
    return (true);
}