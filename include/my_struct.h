/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** My RPG Header
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H
#include "my_rpg.h"

typedef struct player_s
{
    char *name;
    int level;
    int xp;
    int skill;
    int gold;
    int win;
    int lose;
    textures_t *sf_sprite;
    sfVector2f pos;
    int pv;
    int agility;
    int strength;
    int resistance;
    int max_pv;
    int max_agility;
    int max_strength;
    int max_resistance;
} player_t;

typedef struct camera_s
{
    sfView *player;
    sfView *map;
    sfVector2f pos;
} camera_t;

typedef struct fighter_s
{
    char *name;
    char *texture;
    int attacked;
    int pv;
    int max_pv;
    int strength;
    int max_strength;
    int resistance;
    int max_resistance;
    int agility;
    int max_agility;
} fighter_t;

typedef struct fight_s
{
    fighter_t *player_1;
    fighter_t *player_2;
} fight_t;
typedef struct game_s
{
    gamestate_t current_state;
    camera_t *camera;
    fight_t *fight;
    player_t *player;
} game_t;

typedef struct quest_s
{
    bool active;
    queststate_t current_quest;
    int hospital_count;
} quest_t;

typedef struct win_s
{
    sfRenderWindow *sf_win;
    scenes_t *scenes;
    game_t *game;
    sfClock *clock;
    float dt;
    quest_t *quest;
    bool show_map;
    bool sound_status;
} win_t;
#endif