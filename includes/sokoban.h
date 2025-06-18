/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <ncurses.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <string.h>
    #include <signal.h>

typedef struct {
    int terminal_height;
    int terminal_width;
    int map_width;
    int map_height;
    int delta_y;
    int delta_x;
} map_info_t;

typedef struct file_s {
    int fd;
    char *buffer;
    ssize_t size;
    char **lines;
} file_t;

typedef struct player_s {
    int x;
    int y;
    int new_x;
    int new_y;
    int dx;
    int dy;
    int dd_x;
    int dd_y;
} player_t;

void get_size_map(char **map, int *width, int *height);
char **my_str_to_word_array(char *buffer);
void move_player(char **map, char **map_original, player_t *player, int key);
int can_move(char **map, int new_x, int new_y);
int win_check(char **map, char **map_original);
char **copy_map(char **map);
void reset_map(char **map, char **map_original);
int can_move(char **map, int new_x, int new_y);
void display_map(char **map);
void get_map_info(char **map, map_info_t *info);
void init_screen(char **map, char **map_original, int *height, int *width);
void find_player(char **map, player_t *player);
void init_ncurses_info(char **map, int *height, int *width, player_t *player);
void file_close(file_t *file);
int file_read(file_t *file);
int file_open(file_t *file, char *filepath);
int open_map(char **argv);
char **load_map(char *filepath, file_t *file);
int my_strcpy(char *dest, const char *src);
int my_strlen(char const *str);
char *my_strdup(const char *src);
int my_strncpy(char *dest, const char *src, int max_len);
bool check_lose_condition(char **map);
int my_strcmp(char const *s1, char const *s2);
bool has_txt_extension(char *filename);
void display_ext_error(void);
#endif
