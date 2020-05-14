/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** end
*/

#include "my_rpg.h"
#include "my_game.h"
#include "my_level.h"
#include "my_gamestate.h"

void end_fight_move_text(scenes_t *scene)
{
    sfVector2f pos = {50, 600};

    sfText_setPosition(get_text(scene->texts, "player_hp")->sf_text, pos);
    pos.x = 950;
    sfText_setPosition(get_text(scene->texts, "enemie_hp")->sf_text, pos);
    pos.y = 50;
    pos.x = 390;
    sfText_setPosition(get_text(scene->texts, "player_name")->sf_text, pos);
    pos.x = 650;
    sfText_setPosition(get_text(scene->texts, "enemie_name")->sf_text, pos);
}

void end_fight_move_button(scenes_t *scene)
{
    sfVector2f pos = {550, 420};

    sfRectangleShape_setPosition(get_button(scene->buttons,
    "continue_hud")->sf_rect, pos);
    pos.y = -200;
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "attack_hud")->sf_rect, pos);
    sfRectangleShape_setPosition(get_button(scene->buttons,
    "block_hud")->sf_rect, pos);
}

void end_fight_load_text(scenes_t *scene, win_t *win, int xp, int gold)
{
    sfText_setString(get_text(scene->texts, "player_attack")->sf_text,
    my_strcat("XP + ", my_itoa(xp)));
    sfText_setString(get_text(scene->texts, "player_hp")->sf_text,
    my_strcat("Gold + ", my_itoa(gold)));
    sfText_setString(get_text(scene->texts, "enemie_attack")->sf_text,
    my_strcat("WINS : ", my_itoa(win->game->player->win)));
    sfText_setString(get_text(scene->texts, "enemie_hp")->sf_text,
    my_strcat("LOSES : ", my_itoa(win->game->player->lose)));
    sfText_setString(get_text(scene->texts, "player_name")->sf_text, "YOU");
}

void end_fight_set_text(win_t *win, scenes_t *scene, bool st)
{
    int xp = (st == true) ? xp_ranking[win->game->player->level] / 4 :
    xp_ranking[win->game->player->level] / 5;
    int gold = (st == true) ? 24 : 12;

    end_fight_load_text(scene, win, xp, gold);
    if (st == true)
        sfText_setString(get_text(scene->texts, "enemie_name")->sf_text,
        "WIN !!");
    else
        sfText_setString(get_text(scene->texts, "enemie_name")->sf_text,
        "LOSE...");
    win->game->player->xp += xp;
    win->game->player->gold += gold;
}

void end_fight(win_t *win, bool status)
{
    const char *scene_name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, scene_name);

    if (status == true)
        win->game->player->win++;
    else
        win->game->player->lose++;
    if (check_win(win, status) || check_lose(win))
        return;
    end_fight_move_button(scene);
    end_fight_move_text(scene);
    end_fight_set_text(win, scene, status);
    win->game->fight->player_1->attacked = 4;
}