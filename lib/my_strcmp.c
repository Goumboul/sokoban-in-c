/*
** EPITECH PROJECT, 2024
** Sokoban
** File description:
** my_strcmp.c
*/

#include "../includes/sokoban.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] != '\0' && s2[a] != '\0') {
        if (s1[a] != s2[a])
            return s1[a] - s2[a];
        a++;
    }
    return s1[a] - s2[a];
}
