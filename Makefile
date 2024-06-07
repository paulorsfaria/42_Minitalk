NAME = client
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft

SRCS = srcs/client.c


OBJS = ${SRCS:.c=.o}

${NAME}:${OBJS}
		${MAKE} --no-print-directory -C ${LIBFT}
		cp ${LIBFT}/libft.a .
		${CC} ${OBJS} libft.a -o ${NAME}

clean:
		${MAKE} --no-print-directory clean -C ${LIBFT}
		rm -fr ${OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ${LIBFT}
		rm -fr libft.a
		rm -fr ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clear fclean re