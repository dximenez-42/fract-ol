NAME = fractol

# Aún más rápido (pero requiere ICX)
CC = icx
CFLAGS = -O3 -xHost -qopt-report=3 -qopt-report-file=stdout -qopenmp -Werror -Wall -Wextra

# Más lento, da fallos visuales por alguna razón
# CC = gcc
# CFLAGS = -O3 -fopenmp -Werror -Wall -Wextra

MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

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
	make all -C minilibx-linux
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make fclean -C printf
	make clean -C minilibx-linux

clean :
	rm -fr $(NAME)
	make clean -C printf
	make clean -C minilibx-linux

re : fclean all