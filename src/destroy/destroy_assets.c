/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Destroy Game Management
*/

#include "my_rpg.h"

static bool destroy_audios(scenes_t *scene)
{
    audios_t *element = scene->audios;
    audios_t *next = NULL;

    while (element != NULL) {
        next = element->next;
        destroy_audio(&scene->audios, element->name);
        element = next;
    }
    return (true);
}

static bool destroy_texts(scenes_t *scene)
{
    texts_t *element = scene->texts;
    texts_t *next = NULL;

    while (element != NULL) {
        next = element->next;
        destroy_text(&scene->texts, element->name);
        element = next;
    }
    return (true);
}

static bool destroy_textures(scenes_t *scene)
{
    textures_t *element = scene->textures;
    textures_t *next = NULL;

    while (element != NULL) {
        next = element->next;
        destroy_texture(&scene->textures, element->name);
        element = next;
    }
    return (true);
}

static bool destroy_buttons(scenes_t *scene)
{
    buttons_t *element = scene->buttons;
    buttons_t *next = NULL;

    while (element != NULL) {
        next = element->next;
        destroy_button(&scene->buttons, element->name);
        element = next;
    }
    return (true);
}

bool destroy_game(win_t *win)
{
    scenes_t *element = win->scenes;
    scenes_t *next = NULL;

    while (element != NULL) {
        next = element->next;
        destroy_audios(element);
        destroy_texts(element);
        destroy_textures(element);
        destroy_buttons(element);
        destroy_scene(&win->scenes, element->name);
        element = next;
    }
    return (true);
}
