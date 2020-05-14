/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef MY_CONFIG_H
#define MY_CONFIG_H
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"

#ifndef MY_CONFIG_STRUCT_H
#define MY_CONFIG_STRUCT_H
typedef struct config_s
{
    const char *name;
    char *data;
    struct config_s *next;
} config_t;
#endif
bool create_config(config_t **config, const char *name, char *data);
config_t *get_config(config_t *config, const char *name);
bool destroy_config(config_t **config, const char *name);
bool load_config(config_t **config, const char *path);
bool save_config(config_t **config, const char *path);
#endif
