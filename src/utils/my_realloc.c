/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** Reallocates memory allocation
*/

#include "my.h"

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;

    if (!ptr || !(new_ptr = malloc(size)))
        return (NULL);
    my_strcpy((char *)new_ptr, (char *)ptr);
    free(ptr);
    return (new_ptr);
}
