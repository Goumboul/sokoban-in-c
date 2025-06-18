/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

static int check_lines(char *line, char *original)
{
    int x = 0;

    while (original[x] != '\0') {
        if (original[x] == 'O' && line[x] != 'X')
            return 0;
        x++;
    }
    return 1;
}

int win_check(char **map, char **map_original)
{
    int y = 0;

    while (map_original[y] != NULL) {
        if (!check_lines(map[y], map_original[y]))
            return 0;
        y++;
    }
    return 1;
}
