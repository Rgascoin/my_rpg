/*
** EPITECH PROJECT, 2019
** my_calloc
** File description:
** Allocate and init memory block
*/

#include "my.h"

void *my_calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(size * nmemb);

    if (!ptr)
        return (NULL);
    my_memset(ptr, 0, size * nmemb);
    return (ptr);
}
