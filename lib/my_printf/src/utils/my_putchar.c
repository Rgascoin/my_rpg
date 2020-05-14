/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar func
*/

#include "my_printf.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
