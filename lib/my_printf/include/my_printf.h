/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Printf Header File
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_printf(char const *format, ...);
int my_putchar(char c);
int my_putstr(char const *str);
int my_put_octal_str(char const *str);
void my_putnbr(int nb);
void my_putnbr_unsigned(unsigned int nb);
void my_putnbr_binary(int nb);
void my_putnbr_octal(int nb);
void my_putnbr_hexa(int nb);
void my_putnbr_hexa_maj(int nb);
void my_putnbr_base(long int nb, char *base);
void my_put_address(long int nb);
int my_strlen(char const *str);
char *my_strdup(char const *str);
#endif
