/*
** EPITECH PROJECT, 2019
** my_config
** File description:
** Config Loader Management
*/

#include "my_config.h"

static int get_height(const char *path)
{
    int height = 0;
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (0);
    while (get_next_line(fd) != NULL)
        height++;
    return (height);
}

static char **read_file(const char *path)
{
    int i = 0;
    int fd = open(path, O_RDONLY);
    char *line = NULL;
    char **config = NULL;

    if (fd == -1)
        return (NULL);
    config = malloc(sizeof(char *) * (get_height(path) + 1));
    if (!config)
        return (NULL);
    while ((line = get_next_line(fd)) != NULL)
        config[i++] = line;
    config[i] = NULL;
    close(fd);
    return (config);
}

static char *get_data(char **lines)
{
    int i = 1;
    char *data = NULL;

    while (lines != NULL && lines[i] != NULL) {
        data = my_strcat(data, lines[i++]);
        data = my_strcat(data, ":");
    }
    return (data);
}

bool load_config(config_t **config, const char *path)
{
    int i = 0;
    char **data = read_file(path);
    char **sline = NULL;

    if (!data)
        return (false);
    while (data[i] != NULL) {
        sline = my_split(data[i++], ":");
        create_config(config, sline[0], get_data(sline));
        if (!get_config(*config, sline[0]))
            return (false);
    }
    return (true);
}
