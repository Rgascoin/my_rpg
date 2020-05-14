/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** render_core
*/

#include "my_rpg.h"
#include "my_gamestate.h"

static void place_hud(scenes_t *scene, win_t *win)
{
    get_texture(scene->textures, "hp")->visible = 1;
    get_texture(scene->textures, "coin")->visible = 1;
    get_texture(scene->textures, "xp")->visible = 1;
    if (win->quest->current_quest == END)
        get_texture(scene->textures, "bandage")->visible = 1;
    if (win->quest->current_quest == HEAL_3_TIMES || win->quest->current_quest
    == END)
        get_texture(scene->textures, "glove")->visible = 1;
    get_texture(scene->textures, "inv")->visible = 1;
}

static void hide_hud(scenes_t *scene)
{
    get_texture(scene->textures, "hp")->visible = 0;
    get_texture(scene->textures, "coin")->visible = 0;
    get_texture(scene->textures, "xp")->visible = 0;
    get_texture(scene->textures, "bandage")->visible = 0;
    get_texture(scene->textures, "glove")->visible = 0;
    get_texture(scene->textures, "inv")->visible = 0;
}

void render_handler(win_t *win)
{
    const char *name = GTSTR[win->game->current_state];
    scenes_t *scene = get_scene(win->scenes, name);

    if (!scene)
        return;
    if (my_strcmp(scene->name, "IN_GAME") == 0) {
        sfRenderWindow_setView(win->sf_win, win->game->camera->player);
        draw_scene(win->sf_win, scene);
        if (win->show_map == true) {
            sfRenderWindow_setView(win->sf_win, win->game->camera->map);
            get_texture(scene->textures, "player_face")->visible = 1;
            hide_hud(scene);
            draw_scene(win->sf_win, scene);
        }
        get_texture(scene->textures, "player_face")->visible = 0;
        place_hud(scene, win);
    } else {
        sfRenderWindow_setView(win->sf_win,
        sfRenderWindow_getDefaultView(win->sf_win));
        draw_scene(win->sf_win, scene);
    }
}
