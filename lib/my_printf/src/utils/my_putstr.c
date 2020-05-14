/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr and my_put_o_str func
*/

#include "my_printf.h"

int my_putstr(char const *str)
{
    if (!str)
        return (-1);
    write(1, str, my_strlen(str));
    return (0);
}

int my_put_octal_str(char const *str)
{
    int i = 0;

    while (str != NULL && str[i] != '\0') {
        if (str[i] >= 32) {
            my_putchar(str[i]);
        } else if (str[i] >= 0 && str[i] <= 7) {
            my_putstr("\\00");
            my_putnbr_base(str[i], "01234567");
        } else {
            my_putstr("\\0");
            my_putnbr_base(str[i], "01234567");
        }
        i++;
    }
    return (0);
}
