/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window
*/

#include "my_rpg.h"
#include "my_env.h"

bool init_window(win_t *win, char **env)
{
    if (!get_env(env, "DISPLAY"))
        return (false);
    win->sf_win = create_window("My RPG", 1280, 720);
    win->game = my_calloc(1, sizeof(game_t));
    if (!win->sf_win || !win->game)
        return (false);
    win->game->player = my_calloc(1, sizeof(player_t));
    win->quest = my_calloc(1, sizeof(quest_t));
    if (win->game->player == NULL || win->quest == NULL)
        return (false);
    win->show_map = true;
    win->sound_status = true;
    return (true);
}