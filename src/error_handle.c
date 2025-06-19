/*
** EPITECH PROJECT, 2024
** Sokoban
** File description:
** error_handle.c
*/

#include "../includes/sokoban.h"

bool has_txt_extension(char *filename)
{
    int len;

    len = my_strlen(filename);
    if (len < 4)
        return false;
    return filename[len - 4] == '.' &&
        filename[len - 3] == 't' &&
        filename[len - 2] == 'x' &&
        filename[len - 1] == 't';
}

void display_ext_error(void)
{
    const char *mess = "map file must have a .txt extension\n";

    write(2, mess, 37);
}

static bool is_valid_char(char c)
{
    return (c == ' ' || c == '\n' || c == '#' ||
        c == 'X' || c == 'O' || c == 'P');
}

static int handle_invalid_char(char c)
{
    if (!is_valid_char(c)) {
        write(2, "invalid character in the map\n", 26);
        return 84;
    }
    return 0;
}

static void update_counts(char c, int *count_x, int *count_o, int *count_p)
{
    switch (c) {
        case 'X':
            (*count_x)++;
            break;
        case 'O':
            (*count_o)++;
            break;
        case 'P':
            (*count_p)++;
            break;
        default:
            break;
    }
}

static void count_line_chars(char *line, int *count_x, int *count_o,
    int *count_p)
{
    for (int x = 0; line[x]; x++) {
        handle_invalid_char(line[x]);
        update_counts(line[x], count_x, count_o, count_p);
    }
}

static void count_elements(char **map, int *count_x, int *count_o,
    int *count_p)
{
    *count_x = 0;
    *count_o = 0;
    *count_p = 0;
    for (int y = 0; map[y]; y++)
        count_line_chars(map[y], count_x, count_o, count_p);
}

int validate_map(char **map)
{
    int count_x;
    int count_o;
    int count_p;

    count_elements(map, &count_x, &count_o, &count_p);
    if (count_p != 1) {
        write(2, "there must be exactly one player (P)\n", 38);
        return 84;
    }
    if (count_x == 0) {
        write(2, "there must be only one box (X)\n", 32);
        return 84;
    }
    if (count_x != count_o) {
        write(2, "number of boxes (X) must match storage (O)\n", 44);
        return 84;
    }
    return 0;
}
