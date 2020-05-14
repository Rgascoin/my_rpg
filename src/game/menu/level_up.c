/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** level_up
*/

#include "my_rpg.h"
#include "my_gamestate.h"

bool update_player_data(scenes_t *scene, win_t *win)
{
    texts_t *text = NULL;

    if ((text = get_text(scene->texts, "pv")) == NULL)
        return (false);
    sfText_setString(text->sf_text, my_strcat(my_strcat(my_strcat("PV : ",
    my_itoa(win->game->player->max_pv)), " --> "),
    my_itoa(win->game->player->max_pv + 5)));
    text = NULL;
    if ((text = get_text(scene->texts, "levelinfo")) == NULL)
        return (false);
    sfText_setString(text->sf_text, my_strcat(my_strcat(my_strcat("LV ",
    my_itoa(win->game->player->level)), " --> LV "),
    my_itoa(win->game->player->level + 1)));
    return (true);
}

bool update_player_skill(scenes_t *scene, win_t *win)
{
    sfText_setString(get_text(scene->texts, "strength")->sf_text,
    my_strcat("STRENGTH : ", my_itoa(win->game->player->max_strength)));
    sfText_setString(get_text(scene->texts, "agility")->sf_text,
    my_strcat("AGILITY : ", my_itoa(win->game->player->max_agility)));
    sfText_setString(get_text(scene->texts, "resistance")->sf_text,
    my_strcat("RESISTANCE : ", my_itoa(win->game->player->max_resistance)));
    sfText_setString(get_text(scene->texts, "points")->sf_text,
    my_strcat("POINTS : ", my_itoa(win->game->player->skill)));
    return (true);
}

bool in_level_up(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    sfVector2f pos = {550, 620};

    if (update_player_data(scene, win) == false
    || update_player_skill(scene, win) == false)
        return (false);
    if (win->game->player->skill <= 0) {
        pos.y = 620;
        pos.x = 550;
    } else
        pos.y = -200;
    sfRectangleShape_setPosition(get_button(scene->buttons, "end")->sf_rect,
    pos);
    return (true);
}