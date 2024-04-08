NAME = fractol

CC = gcc
CFLAGS = #-fsanitize=address -g #-Werror -Wall -Wextra
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -O3

SRCS = 	fractol.c\
		src/window.c\
		src/hooks.c\
		src/input.c\
		src/math.c\
		src/string.c\
		src/fractals.c\
		printf/libftprintf.a\

$(NAME) :
	make all -C printf
	# make all -C minilibx-linux
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make fclean -C printf
	# make clean -C minilibx-linux

clean :
	rm -fr $(NAME)
	make clean -C printf
	# make clean -C minilibx-linux

re : fclean all