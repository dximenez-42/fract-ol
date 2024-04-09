NAME = fractol

CC = gcc
CFLAGS = -O3 #-g -fsanitize=address -Werror -Wall -Wextra
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRCS = 	fractol.c\
		window.c\
		hooks.c\
		input.c\
		math.c\
		string.c\
		fractals.c

BONUS_SRCS = $(wildcard bonus/*.c)
NORMAL_SRCS = $(wildcard src/*.c)

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

$(NAME) : $(NORMAL_SRCS) $(PRINTF_LIB)
	make all -C minilibx-linux
	$(CC) $(CFLAGS) $(NORMAL_SRCS) -o $(NAME) $(MLXFLAGS) -I$(PRINTF_DIR) $(PRINTF_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_SRCS) $(PRINTF_LIB)
	make all -C minilibx-linux
	$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(NAME) $(MLXFLAGS) -I$(PRINTF_DIR) $(PRINTF_LIB)

all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make clean -C minilibx-linux

clean :
	rm -fr $(NAME)
	make clean -C minilibx-linux

re : fclean all
