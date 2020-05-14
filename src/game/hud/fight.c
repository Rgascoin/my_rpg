/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "my_rpg.h"
#include "my_gamestate.h"

bool fight_hud_update(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    if (!scene)
        return (false);
    sfText_setString(get_text(scene->texts, "player_name")->sf_text,
    win->game->fight->player_1->name);
    sfText_setString(get_text(scene->texts, "player_hp")->sf_text,
    my_strcat(my_itoa(win->game->fight->player_1->pv),
    my_strcat("/", my_itoa(win->game->fight->player_1->max_pv))));
    sfText_setString(get_text(scene->texts, "enemie_name")->sf_text,
    win->game->fight->player_2->name);
    sfText_setString(get_text(scene->texts, "enemie_hp")->sf_text,
    my_strcat(my_itoa(win->game->fight->player_2->pv), my_strcat("/",
    my_itoa(win->game->fight->player_2->max_pv))));
    return (true);
}