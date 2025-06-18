/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

void display_map(char **map)
{
    map_info_t info;

    get_map_info(map, &info);
    clear();
    for (int y = 0; map[y]; y++) {
        mvprintw(info.delta_y + y, info.delta_x, "%s", map[y]);
    }
    refresh();
}
