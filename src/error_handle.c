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
