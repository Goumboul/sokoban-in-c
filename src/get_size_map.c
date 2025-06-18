/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

void get_size_map(char **map, int *width, int *height)
{
    int w = 0;
    int h = 0;
    int len = 0;

    for (int i = 0; map[i]; i++) {
        len = my_strlen(map[i]);
        if (len > w)
            w = len;
        h++;
    }
    *width = w;
    *height = h;
}

void get_map_info(char **map, map_info_t *info)
{
    getmaxyx(stdscr, info->terminal_height, info->terminal_width);
    get_size_map(map, &info->map_width, &info->map_height);
    info->delta_y = (info->terminal_height - info->map_height) / 2;
    info->delta_x = (info->terminal_width - info->map_width) / 2;
}
