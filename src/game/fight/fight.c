/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "my_rpg.h"
#include "my_game.h"
#include "my_gamestate.h"

void enemie_attack_bash(int attack, win_t *win, scenes_t *scene)
{
    if (attack == 1) {
        win->game->fight->player_1->pv -=
        (2 + win->game->fight->player_2->strength -
        win->game->fight->player_1->resistance > 0) ? 2 +
        win->game->fight->player_2->strength -
        win->game->fight->player_1->resistance : 0;
        sfText_setString(get_text(scene->texts, "enemie_attack")->sf_text,
        my_strcat("BASH : ", my_itoa(2 + win->game->fight->player_2->strength -
        win->game->fight->player_1->resistance)));
    }
}

void enemie_attack_foot(int attack, win_t *win, scenes_t *scene)
{
    if (attack == 2) {
        win->game->fight->player_1->pv -=
        (2 + win->game->fight->player_2->agility -
        win->game->fight->player_1->resistance > 0) ? 2 +
        win->game->fight->player_2->agility -
        win->game->fight->player_1->resistance : 0;
        sfText_setString(get_text(scene->texts, "enemie_attack")->sf_text,
        my_strcat("FOOT : ", my_itoa(2 + win->game->fight->player_2->agility -
        win->game->fight->player_1->resistance)));
    }
}

void enemie_attack_missed(int attack, win_t *win, scenes_t *scene)
{
    if (attack == 3) {
        win->game->fight->player_1->pv -= 0;
        sfText_setString(get_text(scene->texts,
        "enemie_attack")->sf_text, my_strcat("MISSED : ", "0"));
    }
}

void enemie_attack(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    int attack = (rand() % 3) + 1;

    enemie_attack_bash(attack, win, scene);
    enemie_attack_foot(attack, win, scene);
    enemie_attack_missed(attack, win, scene);
}

bool in_fight(win_t *win)
{
    if (win->game->fight->player_1->attacked != 4) {
        if (animate_management(win) == false || fight_hud_update(win) == false)
            return (false);
    }
    if (win->game->fight->player_1->attacked == 1)
        win->game->fight->player_1->attacked = 2;
    if (win->game->fight->player_1->attacked == 2)
        animate_player_punch(win);
    if (win->game->fight->player_1->attacked == 3)
        player_punch_backward(win);
    if (win->game->fight->player_2->pv <= 0
    && win->game->fight->player_1->attacked == 0)
        end_fight(win, true);
    if (win->game->fight->player_1->pv <= 0
    && win->game->fight->player_1->attacked == 0)
        end_fight(win, false);
    return (true);
}
