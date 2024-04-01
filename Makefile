NAME = fractol

CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address

SRCS = 	fractol.c\
		minilibx/libmlx.a\
		libft/libft.a\

$(NAME) :
	make all -C libft
	# make all -C minilibx
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make fclean -C libft
	# make clean -C minilibx

clean :
	rm -fr $(NAME)
	make clean -C libft
	# make clean -C minilibx

re : fclean all