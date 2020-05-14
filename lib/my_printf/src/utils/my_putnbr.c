/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** my_putnbr func
*/

#include "my_printf.h"

void my_putnbr(int nb)
{
    long int nbr = nb;

    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr > 9) {
        my_putnbr(nbr / 10);
        my_putnbr(nbr % 10);
    } else {
        nbr = nbr + '0';
        my_putchar(nbr);
    }
}

void my_putnbr_unsigned(unsigned int nb)
{
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        nb += '0';
        my_putchar(nb);
    }
}
