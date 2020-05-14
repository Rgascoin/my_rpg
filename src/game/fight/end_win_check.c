/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Check Win and Lose
*/

#include "my_rpg.h"
#include "my_game.h"

bool check_win(win_t *win, bool status)
{
    scenes_t *scene = get_scene(win->scenes, "POST_GAME");
    texts_t *text = NULL;

    if (!scene || !(text = get_text(scene->texts, "win_text")))
        return (false);
    if (win->game->player->level >= 10) {
        if (status)
            sfText_setString(text->sf_text, "Victory!");
        else
            sfText_setString(text->sf_text, "Defeat!");
        set_gamestate(win->game, POST_GAME);
        return (true);
    }
    return (false);
}

bool check_lose(win_t *win)
{
    scenes_t *scene = get_scene(win->scenes, "POST_GAME");
    texts_t *text = NULL;

    if (!scene || !(text = get_text(scene->texts, "win_text")))
        return (false);
    if (win->game->player->lose >= 3) {
        set_gamestate(win->game, POST_GAME);
        sfText_setString(text->sf_text, "Defeat!");
        return (true);
    }
    return (false);
}
