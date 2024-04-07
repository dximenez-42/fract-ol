NAME = fractol

CC = gcc
CFLAGS = #-Werror -Wall -Wextra #-fsanitize=address
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = 	fractol.c\
		src/window.c\
		src/hooks.c\
		src/input.c\
		src/errors.c\
		src/math.c\
		src/mandelbrot.c\
		mlx/libmlx.a\
		libft/libft.a\
		printf/libftprintf.a\

$(NAME) :
	make all -C libft
	make all -C printf
	# make all -C mlx
	gcc $(CFLAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(MLXFLAGS) -c $< -o $@

all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make fclean -C libft
	make fclean -C printf
	# make clean -C mlx

clean :
	rm -fr $(NAME)
	make clean -C libft
	make clean -C printf
	# make clean -C mlx

re : fclean all