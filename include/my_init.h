/*
** EPITECH PROJECT, 2020
** RPG_NORM_MDR
** File description:
** my_init
*/

#ifndef MY_INIT_H_
#define MY_INIT_H_
#include "my_rpg.h"

bool init_window(win_t *win, char **env);
bool init_game(win_t *win);
bool init_main_menu(win_t *win);
bool init_option_menu(win_t *win);
bool init_howtoplay_menu(win_t *win);
bool init_pause_menu(win_t *win);
bool init_level_up(win_t *win);
bool init_inventory(win_t *win);
bool init_fight(win_t *win);
bool init_end_menu(win_t *win);
bool place_inv(scenes_t *scene);
bool init_npc(scenes_t *scene);
bool init_quest(scenes_t *scene);
bool init_hud(scenes_t *scene);
bool init_camera(win_t *win);
bool init_player(scenes_t *scene);
bool init_core(win_t *win);
#endif /* !MY_INIT_H_ */
