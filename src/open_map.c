/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

void free_map(char **map)
{
    if (!map)
        return;
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

int open_map(char **argv)
{
    file_t file = { .fd = -1, .buffer = NULL, .size = 0 };
    char **map = load_map(argv[1], &file);
    int width = 0;
    int height = 0;
    char **copy = copy_map(map);

    if (!map)
        return 84;
    if (!copy) {
        free_map(map);
        file_close(&file);
        return 84;
    }
    init_screen(map, copy, &width, &height);
    free_map(map);
    free_map(copy);
    file_close(&file);
    return 0;
}
