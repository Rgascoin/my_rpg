/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** attack
*/

#include "my_rpg.h"
#include "my_game.h"
#include "my_gamestate.h"

void fight_block(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    if (win->game->fight->player_1->attacked != 0)
        return;
    sfText_setString(get_text(scene->texts, "player_attack")->sf_text,
    my_strcat("BLOCK : ", my_itoa(win->game->fight->player_1->resistance + 4)));
    win->game->fight->player_1->attacked = 1;
    win->game->fight->player_1->resistance += 4;
    back_fight(win);
}

void fight_upercut(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    if (win->game->fight->player_1->attacked != 0
    || win->game->fight->player_1->max_strength < 5) {
        back_fight(win);
        return;
    }
    sfText_setString(get_text(scene->texts, "player_attack")->sf_text,
    my_strcat("UPERCUT : ", my_itoa(2 + win->game->fight->player_1->strength)));
    win->game->fight->player_2->pv -=
    (2 + win->game->fight->player_1->strength > 0) ? 2 +
    win->game->fight->player_1->strength : 0;
    win->game->fight->player_1->attacked = 1;
    back_fight(win);
}

void fight_kick(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    int mult = 1;

    if (win->game->fight->player_1->attacked != 0)
        return;
    if ((rand() % 4) == 1 && (win->quest->current_quest == WIN_3_TIMES
    || win->quest->current_quest == END))
        mult = 2;
    sfText_setString(get_text(scene->texts, "player_attack")->sf_text,
    my_strcat("KICK : ", my_itoa(mult *
    (2 + win->game->fight->player_1->agility -
    win->game->fight->player_2->resistance))));
    win->game->fight->player_2->pv -= (2 + win->game->fight->player_1->agility
    - win->game->fight->player_2->resistance > 0) ? mult *
    (2 + win->game->fight->player_1->agility -
    win->game->fight->player_2->resistance) : 0;
    win->game->fight->player_1->attacked = 1;
    back_fight(win);
}

void fight_punch(win_t *win)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);
    int mult = 1;

    if (win->game->fight->player_1->attacked != 0)
        return;
    if ((rand() % 4) == 1 && (win->quest->current_quest == WIN_3_TIMES
    || win->quest->current_quest == END))
        mult = 2;
    sfText_setString(get_text(scene->texts, "player_attack")->sf_text,
    my_strcat("PUNCH : ", my_itoa(mult *
    (2 + win->game->fight->player_1->strength -
    win->game->fight->player_2->resistance))));
    win->game->fight->player_2->pv -=
    (2 + win->game->fight->player_1->strength -
    win->game->fight->player_2->resistance > 0) ? mult *
    (2 + win->game->fight->player_1->strength -
    win->game->fight->player_2->resistance) : 0;
    win->game->fight->player_1->attacked = 1;
    back_fight(win);
}