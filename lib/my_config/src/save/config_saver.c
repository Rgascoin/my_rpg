/*
** EPITECH PROJECT, 2019
** my_config
** File description:
** Config Save Management
*/

#include "my_config.h"

static int count_config(config_t *config)
{
    int count = 0;
    config_t *element = config;

    while (element != NULL) {
        count++;
        element = element->next;
    }
    return (count);
}

static bool save_file(const char *path, char **data)
{
    int y = 0;
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

    if (fd == -1)
        return (false);
    while (data != NULL && data[y] != NULL) {
        write(fd, data[y], my_strlen(data[y]));
        write(fd, "\n", 1);
        y++;
    }
    return (true);
}

bool save_config(config_t **config, const char *path)
{
    int i = 0;
    config_t *element = *config;
    char *line = NULL;
    char **data = malloc(sizeof(char *) * (count_config(*config) + 1));

    if (!data)
        return (false);
    while (element != NULL) {
        line = my_strcat(element->name, "=");
        line = my_strcat(line, element->data);
        data[i++] = line;
        element = element->next;
    }
    data[i] = NULL;
    save_file(path, data);
    return (true);
}
