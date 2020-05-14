/*
** EPITECH PROJECT, 2019
** my_nblen
** File description:
** Count size of number
*/

int my_intlen(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb *= -1;
        i++;
    }
    if (nb == 0)
        return (1);
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return (i);
}
