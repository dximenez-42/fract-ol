NAME = fractol

CC = gcc
CFLAGS = -O3 #-g -fsanitize=address -Werror -Wall -Wextra
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

NORMAL_SRCS = 	src/fractol.c\
				src/window.c\
				src/hooks.c\
				src/input.c\
				src/math.c\
				src/string.c\
				src/fractals.c

BONUS_SRCS = 	bonus/fractol_bonus.c\
				bonus/window_bonus.c\
				bonus/hooks_bonus.c\
				bonus/input_bonus.c\
				bonus/math_bonus.c\
				bonus/string_bonus.c\
				bonus/fractals_bonus.c

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
