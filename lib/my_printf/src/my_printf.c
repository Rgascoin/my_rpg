/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printf function
*/

#include "my_printf.h"

static void init_fptr(void (**fptr)())
{
    fptr[0] = (void *) &my_putstr;
    fptr[1] = (void *) &my_put_octal_str;
    fptr[2] = &my_putnbr;
    fptr[3] = &my_putnbr;
    fptr[4] = (void *) &my_putchar;
    fptr[5] = &my_putnbr_unsigned;
    fptr[6] = &my_putnbr_binary;
    fptr[7] = &my_putnbr_octal;
    fptr[8] = &my_putnbr_hexa;
    fptr[9] = &my_putnbr_hexa_maj;
    fptr[10] = &my_put_address;
}

static void print_flag(char flag, void (**fptr)(), va_list args)
{
    int i = 0;
    char *flags = "sSdicuboxXp";

    while (flags[i]) {
        if (flag == '%') {
            my_putchar('%');
            return;
        }
        if (flags[i] == flag)
            fptr[i](va_arg(args, void *));
        i++;
    }
}

int my_printf(const char *format, ...)
{
    int i = 0;
    void (*fptr[11])();
    va_list args;

    va_start(args, format);
    init_fptr(fptr);
    while (format[i]) {
        if (format[i] == '%')
            print_flag(format[++i], fptr, args);
        else
            my_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (0);
}
