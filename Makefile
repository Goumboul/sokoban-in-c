##
## EPITECH PROJECT, 2025
## make
## File description:
## Makefile
##

NAME = my_sokoban

SRC = src/main.c	\
	  src/player.c	\
	  src/get_size_map.c	\
	  lib/my_str_to_array.c	\
	  lib/my_strdup.c \
	  src/check_win.c \
	  src/reset_map.c	\
	  src/cpy_map.c	\
	  src/move.c	\
	  src/display.c	\
	  src/screen_setup.c	\
	  src/open_map.c \
	  lib/my_strdup.c	\
	  src/load_map.c	\
	  lib/my_strlen.c	\
	  lib/my_strncpy.c


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Iinclude -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
