/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** mini
*/


#include "../includes/sokoban.h"

static void resize_handler(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)info;
    (void)context;
}

void init_ncurses_info(char **map, int *height,
    int *width, player_t *player)
{
    struct sigaction sa = {
        .sa_sigaction = resize_handler,
        .sa_flags = SA_SIGINFO
    };

    get_size_map(map, width, height);
    find_player(map, player);
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    sigemptyset(&sa.sa_mask);
    refresh();
    sigaction(SIGWINCH, &sa, NULL);
}

static void update_map_info(char **map, map_info_t *info)
{
    getmaxyx(stdscr, info->terminal_height, info->terminal_width);
    get_size_map(map, &info->map_width, &info->map_height);
    info->delta_y = (info->terminal_height - info->map_height) / 2;
    info->delta_x = (info->terminal_width - info->map_width) / 2;
}

static bool resize_loop(map_info_t *info)
{
    int key;

    while (info->terminal_height < info->map_height ||
        info->terminal_width < info->map_width) {
        clear();
        mvprintw(info->terminal_height / 2,
            (info->terminal_width - 20) / 2, "Terminal trop petit");
        mvprintw(info->terminal_height / 2 + 1,
            (info->terminal_width - 30) / 2, "appuyer sur 'q' pour quitter");
        refresh();
        key = getch();
        if (key == 'q')
            return true;
        getmaxyx(stdscr, info->terminal_height, info->terminal_width);
    }
    return false;
}

static void render_game(char **map, player_t *player, map_info_t *info)
{
    display_map(map);
    mvprintw(info->delta_y + player->y, info->delta_x + player->x, "P");
    refresh();
}

static bool check_victory(char **map, char **map_original, map_info_t *info)
{
    if (win_check(map, map_original)) {
        mvprintw(info->terminal_height / 2,
            (info->terminal_width - 8) / 2, "You Win");
        refresh();
        getch();
        return true;
    }
    return false;
}

static bool input(int key, char **map,
    char **map_original, player_t *player)
{
    if (key == 'q')
        return true;
    if (key == ' ') {
        reset_map(map, map_original);
        find_player(map, player);
        return false;
    }
    move_player(map, map_original, player, key);
    return false;
}

void init_screen(char **map, char **map_original, int *height, int *width)
{
    int key;
    player_t player = {0, 0, 0, 0, 0, 0, 0, 0};
    map_info_t info;

    init_ncurses_info(map, height, width, &player);
    clear();
    while (1) {
        update_map_info(map, &info);
        if (resize_loop(&info))
            break;
        render_game(map, &player, &info);
        if (check_victory(map, map_original, &info))
            break;
        key = getch();
        if (input(key, map, map_original, &player))
            break;
    }
    endwin();
}
