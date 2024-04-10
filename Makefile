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

LIBS = -Lminilibx-linux -lmlx_Linux
LIB_FLAGS = -lX11 -lXext

all: $(NAME)


$(NAME): $(NORMAL_OBJS) printf
	$(CC) $(NORMAL_OBJS) $(PRINTF) $(LIBS) $(LIB_FLAGS) -I src/fractol.h -o $(NAME) -v

%.o:%.c
	$(CC) $(CFLAGS) -c -Imlx -DGL_SILENCE_DEPRECATION $< -o $@ 

printf:
	make -C printf

bonus: $(BONUS_OBJS)
	make -C printf
	$(CC) $(BONUS_OBJS) $(PRINTF) $(LIBS) $(LIB_FLAGS) -I bonus/fractol_bonus.h -o $(NAME) -v

clean:
	rm -f $(NORMAL_OBJS)
	rm -f $(BONUS_OBJS)
	$(MAKE) fclean -C printf

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C printf

re: fclean all

.PHONY: fclean clean printf