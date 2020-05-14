/*
** EPITECH PROJECT, 2019
** my_getnextline
** File description:
** Get Line
*/

#include "my.h"

static char *get_buff(char *data)
{
    int i = 0;
    int j = 0;
    char *line = malloc(sizeof(char) * (my_strlen(data) + 1));

    if (!line)
        return (NULL);
    while (data != NULL && data[i] != '\0' && data[i] != '\n')
        i++;
    (data != NULL && data[i] != '\0' && data[i] == '\n') ? i++ : 0;
    while (data != NULL && data[i] != '\0')
        line[j++] = data[i++];
    line[j] = '\0';
    return (line);
}

static char *get_line(char *data)
{
    int i = 0;
    int j = 0;
    char *line = malloc(sizeof(char) * (my_strlen(data) + 1));

    if (!line)
        return (NULL);
    while (data != NULL && data[i] != '\0' && data[i] != '\n')
        line[j++] = data[i++];
    line[j] = '\0';
    return (line);
}

static int has_backspace(char *data)
{
    int i = 0;

    while (data != NULL && data[i] != '\0') {
        if (data[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *get_next_line(int fd)
{
    int size = 0;
    char *data = malloc(sizeof(char) * (READ_SIZE + 1));
    char *line = NULL;
    static char *buff = NULL;

    if (fd == -1 || READ_SIZE <= 0 || !data)
        return (NULL);
    while (!has_backspace(buff) && (size = read(fd, data, READ_SIZE)) > 0) {
        data[size] = '\0';
        line = my_strcat(line, data);
        line = get_line(line);
        (buff != NULL) ? line = my_strcat(buff, line) : 0;
        buff = get_buff(data);
        if (has_backspace(data))
            return (line);
    }
    (buff != NULL && buff[0] != '\0') ? line = get_line(buff) : 0;
    (buff != NULL && buff[0] != '\0') ? buff = get_buff(buff) : 0;
    free(data);
    return (line);
}
