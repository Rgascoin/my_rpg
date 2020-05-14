/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Print number based on a base
*/

#include "my_printf.h"

void my_putnbr_binary(int nb)
{
    my_putnbr_base(nb, "01");
}

void my_putnbr_hexa(int nb)
{
    my_putnbr_base(nb, "0123456789abcdef");
}

void my_putnbr_hexa_maj(int nb)
{
    my_putnbr_base(nb, "0123456789ABCDEF");
}

void my_putnbr_octal(int nb)
{
    my_putnbr_base(nb, "01234567");
}

void my_putnbr_base(long int nb, char *base)
{
    int len = my_strlen(base);

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb > len - 1) {
        my_putnbr_base(nb / len, base);
        my_putnbr_base(nb % len, base);
    } else {
        nb = base[nb];
        my_putchar(nb);
    }
}
