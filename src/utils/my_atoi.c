/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** Return a number as string
*/

int my_atoi(char const *str)
{
    int i = 0;
    int long nb = 0;
    int sign = 1;

    if (!str)
        return (0);
    if (str[i] == '-') {
        nb *= -1;
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (((nb * 10) + (str[i] - 48)) * sign > 2147483647)
            return (0);
        if (((nb * 10) + (str[i] - 48)) * sign < -2147483648)
            return (0);
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    return (nb * sign);
}
