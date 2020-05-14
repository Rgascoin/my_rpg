/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Scene Loader Management
*/

#include "my_rpg.h"
#include "my_yml.h"

bool load_scene(scenes_t *scene, const char *path)
{
    if (!scene)
        return (false);
    if (!load_audios(&scene->audios, path)
        || !load_textures(&scene->textures, path)
        || !load_buttons(&scene->buttons, &scene->textures, path)
        || !load_texts(&scene->texts, path))
        return (false);
    return (true);
}
