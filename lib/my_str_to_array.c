/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#include "../includes/sokoban.h"

static size_t count_lines(char *buffer)
{
    size_t i = 0;
    size_t lines = 0;

    if (!buffer)
        return 0;
    while (buffer[i]) {
        if (buffer[i] == '\n')
            lines++;
        i++;
    }
    if (i > 0 && buffer[i - 1] != '\n')
        lines++;
    return lines;
}

static char *my_strndup(const char *src, int len)
{
    char *dest = malloc(len + 1);
    int i = 0;

    if (!dest)
        return NULL;
    while (i < len && src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static int fill_lines(char **lines, char *buffer)
{
    size_t i = 0;
    size_t j = 0;
    size_t start = 0;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] != '\n')
            continue;
        lines[j] = my_strndup(buffer + start, i - start);
        if (!lines[j])
            return -1;
        j++;
        start = i + 1;
    }
    if (start < i) {
        lines[j] = my_strndup(buffer + start, i - start);
        if (!lines[j])
            return -1;
    }
    return 0;
}

char **my_str_to_word_array(char *buffer)
{
    char **lines = NULL;
    size_t nb_lines = count_lines(buffer);

    lines = malloc(sizeof(char *) * (nb_lines + 1));
    if (!lines)
        return NULL;
    lines[nb_lines] = 0;
    if (fill_lines(lines, buffer) == -1) {
        for (size_t k = 0; k < nb_lines; k++)
            free(lines[k]);
        free(lines);
        return NULL;
    }
    return lines;
}
