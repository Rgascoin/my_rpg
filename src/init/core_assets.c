/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** core_assets
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_load_core.h"
#include "my_init.h"

static void set_player_pos(win_t *win)
{
    player_t *player = my_calloc(1, sizeof(*player));

    player->pos.x = 300;
    player->pos.y = 350;
    player->level = 1;
    player->skill = 0;
    player->gold = 50;
    player->win = 0;
    player->xp = 0;
    player->lose = 0;
    player->name = "Winnie";
    player->pv = 10;
    player->max_pv = 10;
    player->agility = 4;
    player->max_agility = 4;
    player->resistance = 2;
    player->max_resistance = 2;
    player->strength = 3;
    player->max_strength = 3;
    win->game->player = player;
}

bool init_core(win_t *win)
{
    scenes_t *scene = NULL;

    set_player_pos(win);
    if (init_camera(win) == false)
        return (false);
    create_scene(&win->scenes, "IN_GAME");
    if (!load_scene((scene = get_scene(win->scenes, "IN_GAME")),
    "config/core.rll"))
        return (false);
    if (!load_error_audio(scene->audios, asset_core_audio)
    || !load_error_button(scene->buttons, asset_core_button)
    || !load_error_text(scene->texts, asset_core_text)
    || !load_error_texture(scene->textures, asset_core_texture))
        return (false);
    if (!init_player(scene) || !init_hud(scene) || !init_npc(scene)
    || !place_inv(scene) || !init_quest(scene))
        return (false);
    sfMusic_play(get_audio(scene->audios, "bracket")->sf_music);
    sfMusic_setLoop(get_audio(scene->audios, "bracket")->sf_music, sfTrue);
    return (true);
}
