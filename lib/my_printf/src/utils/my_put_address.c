/*
** EPITECH PROJECT, 2019
** my_putnbr_address
** File description:
** Print address
*/

#include "my_printf.h"

void my_put_address(long int nb)
{
    if (nb == 0) {
        my_putstr("(nil)");
    } else {
        my_putstr("0x");
        my_putnbr_base(nb, "0123456789abcdef");
    }
}
