/*
** EPITECH PROJECT, 2019
** my_h
** File description:
** My Header File
*/

#ifndef MY_H
#define MY_H

#ifndef READ_SIZE
#define READ_SIZE (128)
#endif

#ifndef SHARED_PTR
#define SHARED_PTR __attribute((__cleanup__(my_free)))
#endif

#define MY_IS_ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define MY_IS_NUM(c) (c >= '0' && c <= '9')
#define MY_IS_ALPHANUM(c) (MY_IS_ALPHA(c) || MY_IS_NUM(c))

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

int my_printf(const char *format, ...);
int my_putchar(char c);
int my_putstr(char const *str);
int my_puterr(char const *str);
void my_putnbr(int nb);
void my_putnbr_base(long int nb, char *base);
char *my_revstr(char *str);
int my_atoi(char const *str);
bool my_atob(char const *str);
char *my_itoa(int nb);
char *my_strcat(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
void *my_calloc(size_t nmemb, size_t size);
bool my_str_is_alphanum(char const *str);
char *my_strdup(char const *str);
char *my_basename(char const *path);
void my_memset(void *s, int c, int size);
int my_strlen(char const *str);
int my_intlen(int nb);
int my_random_between(int min, int max);
char *get_next_line(int fd);
char **my_split(char const *str, const char *delim);
void my_free(void *s);
#endif
