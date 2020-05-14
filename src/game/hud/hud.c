/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hud
*/

#include "my_rpg.h"
#include "my_gamestate.h"
#include "my_level.h"

bool update_hud(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    texts_t *text = NULL;

    if (!scene || (text = get_text(scene->texts, "player_hp")) == NULL)
        return (false);
    sfText_setString(text->sf_text, my_strcat(my_itoa(win->game->player->pv),
    my_strcat("/", my_itoa(win->game->player->max_pv))));
    if ((text = get_text(scene->texts, "player_gold")) == NULL)
        return (false);
    sfText_setString(text->sf_text, my_itoa(win->game->player->gold));
    if ((text = get_text(scene->texts, "player_xp")) == NULL)
        return (false);
    sfText_setString(text->sf_text, my_strcat(my_itoa(win->game->player->xp),
    my_strcat("/", my_itoa(xp_ranking[win->game->player->level]))));
    return (true);
}