/*
** EPITECH PROJECT, 2020
** RPG_NORM_MDR
** File description:
** my_callback
*/

#ifndef MY_CALLBACK_H_
#define MY_CALLBACK_H_
#include "my_rpg.h"

// Callback
void launch_game(win_t *win);
void main_howtoplay_button(win_t *win);
void main_option_button(win_t *win);
void nothing(win_t *win);
bool quit_game(win_t *win);
void end_levelup(win_t *win);
void back_to_game(win_t *win);
void back_fight(win_t *win);
void show_attack(win_t *win);
void fight_punch(win_t *win);
void fight_kick(win_t *win);
void fight_upercut(win_t *win);
void fight_block(win_t *win);
void sound_option(win_t *win);
void back_to_menu(win_t *win);
void up_agi(win_t *win);
void up_str(win_t *win);
void up_resi(win_t *win);
void option_display_map(win_t *win);
void option_sound(win_t *win);

static const char *name_callback[] =
{
    "launch_game",
    "quit_game",
    "main_option_button",
    "main_howtoplay_button",
    "back_to_menu",
    "sound_option",
    "show_attack",
    "back_fight",
    "fight_punch",
    "fight_kick",
    "fight_upercut",
    "fight_block",
    "back_to_game",
    "up_agi",
    "up_resi",
    "up_str",
    "end_levelup",
    "nothing",
    "option_display_map",
    "option_sound"
};

static void *fct_callback[] =
{
    launch_game,
    quit_game,
    main_option_button,
    main_howtoplay_button,
    back_to_menu,
    sound_option,
    show_attack,
    back_fight,
    fight_punch,
    fight_kick,
    fight_upercut,
    fight_block,
    back_to_game,
    up_agi,
    up_resi,
    up_str,
    end_levelup,
    nothing,
    option_display_map,
    option_sound
};
#endif /* !MY_CALLBACK_H_ */