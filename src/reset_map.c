/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

void reset_map(char **map, char **map_original)
{
    for (int i = 0; map_original[i]; i++) {
        free(map[i]);
        map[i] = my_strdup(map_original[i]);
    }
}
