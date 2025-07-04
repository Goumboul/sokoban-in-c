/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

char **load_map(char *filepath, file_t *file)
{
    char **map = NULL;

    if (file_open(file, filepath) == 84)
        return NULL;
    if (file_read(file) == 84) {
        file_close(file);
        return NULL;
    }
    map = my_str_to_word_array(file->buffer);
    if (!map) {
        file_close(file);
        return NULL;
    }
    return map;
}

void reset_case(char **map, char **map_original, int y, int x)
{
    if (!case_exists(map, y, x) || !case_exists(map_original, y, x))
        return;
    if (map_original[y][x] == 'O')
        map[y][x] = 'O';
    else
        map[y][x] = ' ';
}
