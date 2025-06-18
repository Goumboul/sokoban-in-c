/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

char *my_strdup(const char *src)
{
    int len = 0;
    char *dup;

    while (src[len])
        len++;
    dup = malloc(len + 1);
    if (!dup)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}
