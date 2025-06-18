/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

int can_move(char **map, int new_x, int new_y)
{
    if (new_y < 0 || new_x < 0)
        return 0;
    if (!map[new_y] || !map[new_y][new_x])
        return 0;
    if (map[new_y][new_x] == '#')
        return 0;
    return 1;
}
