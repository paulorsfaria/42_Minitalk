NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft

SRCS_CLIENT = srcs/client.c
SRCS_SERVER = srcs/server.c
SRCS_CLIENT_BONUS = srcs_bonus/client_bonus.c
SRCS_SERVER_BONUS = srcs_bonus/server_bonus.c
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT_BONUS = ${SRCS_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS = ${SRCS_SERVER_BONUS:.c=.o}

${NAME_CLIENT}: ${OBJS_CLIENT} ${OBJS_SERVER}
				${MAKE} --no-print-directory -C ${LIBFT}
				cp ${LIBFT}/libft.a .
				${CC} ${OBJS_CLIENT} libft.a -o ${NAME_CLIENT}
				${CC} ${OBJS_SERVER} libft.a -o ${NAME_SERVER}

${NAME_CLIENT_BONUS}: ${OBJS_CLIENT_BONUS} ${OBJS_SERVER_BONUS}
					${MAKE} --no-print-directory -C ${LIBFT}
					cp ${LIBFT}/libft.a .
					${CC} ${OBJS_CLIENT_BONUS} libft.a -o ${NAME_CLIENT_BONUS}
					${CC} ${OBJS_SERVER_BONUS} libft.a -o ${NAME_SERVER_BONUS}

bonus: ${NAME_CLIENT_BONUS}

clean:
		${MAKE} --no-print-directory clean -C ${LIBFT}
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
		${RM} ${OBJS_CLIENT_BONUS} ${OBJS_SERVER_BONUS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ${LIBFT}
		${RM} libft.a
		${RM} ${NAME_CLIENT} ${NAME_SERVER}
		${RM} ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

all:${NAME_CLIENT}

re: fclean all

.PHONY: all clear fclean re bonus
