NAME	= fractol

CC = gcc
CFLAGS= -Wall -Werror -Wextra

SRC =	fractol.c\
		window.c\
		hooks.c\
		input.c\
		math.c\
		string.c\
		fractals.c
SRCS = $(addprefix ./src/, $(SRC))

BONUS_SRC =	fractol_bonus.c\
			window_bonus.c\
			hooks_bonus.c\
			input_bonus.c\
			math_bonus.c\
			string_bonus.c\
			fractals_bonus.c
BONUS_SRCS = $(addprefix ./bonus/, $(SRC))


NORMAL_OBJS	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

PRINTF	= printf/libftprintf.a

LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)


$(NAME): $(NORMAL_OBJS) printf mlx
	$(CC) $(NORMAL_OBJS) $(PRINTF) $(LIBS) -I src/fractol.h -o $(NAME) -v

%.o:%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

printf:
	make -C printf

mlx:
	make -C minilibx-linux

bonus: $(BONUS_OBJS)
	printf
	mlx
	$(CC) $(BONUS_OBJS) $(PRINTF) $(LIBS) -I bonus/fractol_bonus.h -o $(NAME) -v

clean:
	rm -f $(NORMAL_OBJS)
	rm -f $(BONUS_OBJS)
	make clean -C printf
	make clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)
	make fclean -C printf
	make clean -C minilibx-linux

re: fclean all

.PHONY: fclean clean printf mlx