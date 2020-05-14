/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Scene Utils Management
*/

#include "my_cgraph.h"

int count_scenes(scenes_t *scenes)
{
    int count = 0;
    scenes_t *element = scenes;

    while (element != NULL) {
        count++;
        element = element->next;
    }
    return (count);
}
