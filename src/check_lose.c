/*
** EPITECH PROJECT, 2024
** Sokoban
** File description:
** check_lose.c
*/

#include "../includes/sokoban.h"

static bool is_wall_or_box(char c)
{
    if (c == '#' || c == 'X')
        return true;
    return false;
}

static bool is_box_blocked(char **map, int y, int x)
{
    bool blocked_top_left = false;
    bool blocked_top_right = false;
    bool blocked_bottom_left = false;
    bool blocked_bottom_right = false;

    if (is_wall_or_box(map[y - 1][x]) && is_wall_or_box(map[y][x - 1]))
        blocked_top_left = true;
    if (is_wall_or_box(map[y - 1][x]) && is_wall_or_box(map[y][x + 1]))
        blocked_top_right = true;
    if (is_wall_or_box(map[y + 1][x]) && is_wall_or_box(map[y][x - 1]))
        blocked_bottom_left = true;
    if (is_wall_or_box(map[y + 1][x]) && is_wall_or_box(map[y][x + 1]))
        blocked_bottom_right = true;
    return (blocked_top_left || blocked_top_right ||
        blocked_bottom_left || blocked_bottom_right);
}

static bool check_row(char **map, int y)
{
    int x = 0;

    while (map[y][x]) {
        if (map[y][x] == 'X' && is_box_blocked(map, y, x))
            return true;
        x++;
    }
    return false;
}

static bool any_box_blocked(char **map)
{
    int y = 0;

    while (map[y]) {
        if (check_row(map, y))
        return true;
        y++;
    }
    return false;
}

bool check_lose_condition(char **map)
{
    return any_box_blocked(map);
}
