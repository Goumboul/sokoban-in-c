/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

int file_open(file_t *file, char *filepath)
{
    struct stat st;

    if (stat(filepath, &st) == -1)
        return 84;
    file->size = st.st_size;
    file->buffer = malloc(file->size + 1);
    if (!file->buffer)
        return 84;
    file->fd = open(filepath, O_RDONLY);
    if (file->fd == -1) {
        free(file->buffer);
        return 84;
    }
    return 0;
}

int file_read(file_t *file)
{
    ssize_t bytes_read = read(file->fd, file->buffer, file->size);

    if (bytes_read != file->size)
        return 84;
    file->buffer[file->size] = '\0';
    return 0;
}

void file_close(file_t *file)
{
    if (file->fd != -1)
        close(file->fd);
    if (file->buffer)
        free(file->buffer);
}

static bool check_p_map(int y, char **map, player_t *player)
{
    for (int x = 0; map[y][x]; x++) {
        if (map[y][x] == 'P') {
            player->x = x;
            player->y = y;
            map[y][x] = ' ';
            return true;
        }
    }
    return false;
}

void find_player(char **map, player_t *player)
{
    for (int y = 0; map[y]; y++) {
        if (check_p_map(y, map, player))
            return;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "Usage: ./program <file>\n", 24);
        return 84;
    }
    if (open_map(argv) == 84)
        return 84;
    return 0;
}
