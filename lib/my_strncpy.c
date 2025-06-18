/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

int my_strncpy(char *dest, const char *src, int max_len)
{
    int i = 0;

    while (i < max_len && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < max_len) {
        dest[i] = '\0';
        i++;
    }
    return i;
}
