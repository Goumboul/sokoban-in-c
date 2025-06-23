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

static bool check_block(char **map, coord_t c1, coord_t c2)
{
    if (!case_exists(map, c1.y, c1.x))
        return false;
    if (!case_exists(map, c2.y, c2.x))
        return false;
    if (!is_wall_or_box(map[c1.y][c1.x]))
        return false;
    if (!is_wall_or_box(map[c2.y][c2.x]))
        return false;
    return true;
}

static bool is_box_blocked(char **map, int y, int x)
{
    coord_t top = {y - 1, x};
    coord_t bottom = {y + 1, x};
    coord_t left = {y, x - 1};
    coord_t right = {y, x + 1};

    if (check_block(map, top, left))
        return true;
    if (check_block(map, top, right))
        return true;
    if (check_block(map, bottom, left))
        return true;
    if (check_block(map, bottom, right)) {
        return true;
    }
    return false;
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
