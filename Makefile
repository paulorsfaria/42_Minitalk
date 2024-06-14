NAME_CLIENT = client
NAME_SERVER = server
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft

SRCS_CLIENT = srcs/client.c
SRCS_SERVER = srcs/server.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

${NAME_CLIENT}:${OBJS_CLIENT} ${OBJS_SERVER}
		${MAKE} --no-print-directory -C ${LIBFT}
		cp ${LIBFT}/libft.a .
		${CC} ${OBJS_CLIENT} libft.a -o ${NAME_CLIENT} && ${CC} ${OBJS_SERVER} libft.a -o ${NAME_SERVER}



clean:
		${MAKE} --no-print-directory clean -C ${LIBFT}
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean: clean
		${MAKE} fclean --no-print-directory -C ${LIBFT}
		${RM} libft.a
		${RM} ${NAME_CLIENT} ${NAME_SERVER}

all: ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clear fclean re