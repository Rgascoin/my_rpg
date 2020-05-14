/*
** EPITECH PROJECT, 2020
** RPG_NORM_MDR
** File description:
** my_game
*/

#ifndef MY_GAME_H_
#define MY_GAME_H_
#include "my_rpg.h"

// Event
void event_handler(win_t *win);
void on_button_clicked(win_t *win, scenes_t *scene);
void on_window_close(win_t *win);
void on_key_pressed(win_t *win);

// Gamestate
gamestate_t get_gamestate(game_t *game);
bool is_gamestate(game_t *game, gamestate_t gamestate);
void set_gamestate(game_t *game, gamestate_t gamestate);
bool game_handler(win_t *win);

// Animation
bool animate_background(win_t *win);
bool animate_player(win_t *win);
bool hide_animation(win_t *win);
void animate_south(scenes_t *scene);
void animate_east(scenes_t *scene);
void animate_west(scenes_t *scene);
void animate_north(scenes_t *scene);
bool animate_arena(win_t *win);
bool animate_rest(win_t *win);
bool animate_rest_bubble(win_t *win);
bool animate_management(win_t *win);
bool player_standing(scenes_t *scene);
bool enemie_standing(scenes_t *scene, fighter_t *enemie);
bool animate_player_punch(win_t *win);

// Menu
bool in_level_up(win_t *win);

// Player
bool player_movements(win_t *win);
void update_level(win_t *win);
bool colider_test(scenes_t *scene, win_t *win, int y, int x);
void move_player(win_t *win);
void heal_player(win_t *win);
void reset_visibility(scenes_t *scene);

// Handler
bool in_game(win_t *win);
bool camera_handler(win_t *win);

// Hud
bool fight_hud_update(win_t *win);
bool update_hud(win_t *win);
void move_hud(scenes_t *scene, float x, float y);

// Quest
bool player_quest(win_t *win);
void quest_status(win_t *win, textures_t *texture);
char *quest_name(win_t *win);
void quest_fight(win_t *win, textures_t *texture);
void quest_heal(win_t *win, textures_t *texture);

// Fight
bool in_fight(win_t *win);
void end_fight(win_t *win, bool status);
bool check_win(win_t *win, bool status);
bool check_lose(win_t *win);
void start_fight(win_t *win);
void set_enemie_texture(win_t *win, fighter_t *enemie);
void set_string(win_t *win);
void move_string(win_t *win);
void back_fight(win_t *win);
void enemie_attack(win_t *win);
bool player_punch_backward(win_t *win);

// Inventory
void open_inv(win_t *win);
void print_stats(win_t *win);
void move_spell(win_t *win);
void move_cross(win_t *win);
#endif /* !MY_GAME_H_ */