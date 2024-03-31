NAME = fractol

CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address

SRCS = 	fractol.c\
		libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	rm -fr $(NAME)
	make fclean -C libft

clean :
	rm -fr $(NAME)
	make clean -C libft

re : fclean all