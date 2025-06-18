/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

static int count_lines(char **map)
{
    int count = 0;

    while (map[count] != NULL)
        count++;
    return count;
}

static void free_copy(char **copy, int cpy)
{
    for (int i = 0; i < cpy; i++)
        free(copy[i]);
    free(copy);
}

char **copy_map(char **map)
{
    int i = 0;
    int size = count_lines(map);
    char **copy = malloc(sizeof(char *) * (size + 1));

    if (!copy)
        return NULL;
    for (i = 0; i < size; i++) {
        copy[i] = my_strdup(map[i]);
        if (!copy[i]) {
            free_copy(copy, i);
            return NULL;
        }
    }
    copy[size] = NULL;
    return copy;
}
