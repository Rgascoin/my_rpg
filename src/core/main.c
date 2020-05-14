/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** My RPG Game
*/

#include "my_rpg.h"
#include "my_core.h"
#include "my_init.h"

static void display_help(char *name)
{
    my_printf("========== My RPG ==========\n"
        "DESCRIPTION:\n"
        "\t My RPG Game.\n"
        "USAGE\n"
        "\t%s [OPTIONS]\n"
        "OPTIONS\n"
        "\t[-h] - Display this help.\n"
        "============================\n",
        name);
}

static bool start_game(char **env)
{
    bool status = false;
    win_t *win = my_calloc(1, sizeof(*win));

    if (!win || !init_window(win, env))
        return (false);
    status = game_loop(win);
    return (status);
}

int main(int ac, char **av, char **env)
{
    bool status = false;

    if (ac > 2)
        return (84);
    else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help(av[0]);
    } else {
        status = start_game(env);
    }
    return (status) ? 0 : 84;
}
