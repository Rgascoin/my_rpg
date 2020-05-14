/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** My enum
*/

#ifndef MY_ENUM_H
#define MY_ENUM_H
typedef enum gamestate_e
{
    PRE_GAME = 0,
    IN_GAME = 1,
    IN_FIGHT = 2,
    IN_INVENTORY = 3,
    IN_LEVELUP = 4,
    IN_PAUSE = 5,
    IN_OPTION = 6,
    IN_HOWTOPLAY = 7,
    POST_GAME = 8
} gamestate_t;

typedef enum queststate_s
{
    BEGIN,
    WIN_3_TIMES,
    HEAL_3_TIMES,
    END,
} queststate_t;
#endif