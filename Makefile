CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putpointer.c ft_putstr.c ft_putnbr_signed.c
OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} ${OBJ}

clean :
	rm -rf ${OBJ}
fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean bonus re
