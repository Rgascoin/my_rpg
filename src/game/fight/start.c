/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start
*/

#include "my_rpg.h"
#include "my_game.h"
#include "my_enemie.h"

void init_user_player(win_t *win, fighter_t *player)
{
    player->name = win->game->player->name;
    player->attacked = 0;
    player->pv = win->game->player->pv;
    player->max_pv = win->game->player->max_pv;
    player->agility = win->game->player->agility;
    player->max_agility = win->game->player->max_agility;
    player->resistance = win->game->player->resistance;
    player->max_resistance = win->game->player->max_resistance;
    player->strength = win->game->player->strength;
    player->max_strength = win->game->player->max_strength;
}

void init_enemy(win_t *win, fighter_t *enemie)
{
    enemie->name = (char *)enemie_name[(rand() % (6 - 0 + 1))];
    enemie->attacked = 0;
    enemie->max_pv = (rand() % ((win->game->player->max_pv + 5) -
    (win->game->player->max_pv - 5) + 1)) + (win->game->player->max_pv - 4);
    enemie->pv = enemie->max_pv;
    enemie->agility = (rand() % ((win->game->player->max_agility + 1) -
    (win->game->player->max_agility - 3) + 1)) +
    (win->game->player->max_agility - 3);
    enemie->max_agility = enemie->agility;
    enemie->resistance = (rand() % (4));
    enemie->max_resistance = enemie->resistance;
    enemie->strength = (rand() % ((win->game->player->max_strength + 1) -
    (win->game->player->max_strength - 3) + 1)) +
    (win->game->player->max_strength - 3);
    enemie->max_strength = enemie->strength;
}

void release_tony(win_t *win, fighter_t *enemie)
{
    enemie->name = "TONY";
    enemie->attacked = 0;
    enemie->max_pv = (rand() % ((win->game->player->max_pv + 5) -
    (win->game->player->max_pv + 2) + 1)) + (win->game->player->max_pv + 2);
    enemie->pv = enemie->max_pv;
    enemie->agility = (rand() % ((win->game->player->max_agility + 3) -
    (win->game->player->max_agility + 1) + 1)) +
    (win->game->player->max_agility + 1);
    enemie->max_agility = enemie->agility;
    enemie->resistance = (rand() % (3));
    enemie->max_resistance = enemie->resistance;
    enemie->strength = (rand() % ((win->game->player->max_strength + 4) -
    (win->game->player->max_strength + 2) + 1)) +
    (win->game->player->max_strength + 2);
    enemie->max_strength = enemie->strength;
}

void start_fight(win_t *win)
{
    fight_t *fight = my_calloc(1, sizeof(fight_t));
    fighter_t *p1 = my_calloc(1, sizeof(fighter_t));
    fighter_t *p2 = my_calloc(1, sizeof(fighter_t));

    (void)enemie_type;
    init_user_player(win, p1);
    (win->game->player->level < 10) ? init_enemy(win, p2) :
    release_tony(win, p2);
    fight->player_1 = p1;
    fight->player_2 = p2;
    win->game->fight = fight;
    set_gamestate(win->game, IN_FIGHT);
    set_enemie_texture(win, fight->player_2);
    set_string(win);
    move_string(win);
    back_fight(win);
}