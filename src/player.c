/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

void reset_case(char **map, char **map_original, int y, int x)
{
    if (map_original[y][x] == 'O')
        map[y][x] = 'O';
    else
        map[y][x] = ' ';
}

static void copyvalues(char **map, player_t *player)
{
    player->x = player->new_x;
    player->y = player->new_y;
    map[player->new_y][player->new_x] = 'P';
}

bool move_box(char **map, char **map_original, player_t *player)
{
    int case_x = player->new_x + player->dx;
    int case_y = player->new_y + player->dy;

    if (case_y < 0 || case_x < 0 ||
            !map[case_y] || !map[case_y][case_x])
        return false;
    if (map[case_y][case_x] == '#' || map[case_y][case_x] == 'X')
        return false;
    reset_case(map, map_original, player->new_y, player->new_x);
    map[case_y][case_x] = 'X';
    return true;
}

void move_player_map(char **map, char **map_original, player_t *player)
{
    reset_case(map, map_original, player->y, player->x);
    copyvalues(map, player);
}

void process_movement(char **map, char **map_original, player_t *player)
{
    char caser = map[player->new_y][player->new_x];

    if (caser == '#')
        return;
    if (caser == 'X') {
        if (move_box(map, map_original, player))
            move_player_map(map, map_original, player);
        return;
    }
    if (caser == ' ' || caser == 'O')
        move_player_map(map, map_original, player);
}

static void player_movement(char **map, char **map_original,
    player_t *player)
{
    player->new_x = player->x + player->dx;
    player->new_y = player->y + player->dy;
    process_movement(map, map_original, player);
}

void move_player(char **map, char **map_original, player_t *player, int key)
{
    player->dx = 0;
    player->dy = 0;
    switch (key) {
        case KEY_UP:
            player->dy = -1;
            break;
        case KEY_DOWN:
            player->dy = 1;
            break;
        case KEY_LEFT:
            player->dx = -1;
            break;
        case KEY_RIGHT:
            player->dx = 1;
            break;
        default:
            return;
    }
    player_movement(map, map_original, player);
}
