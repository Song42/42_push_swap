SRCS		= main.c \
		  s_commands.c \
		  r_commands.c \
		  rr_commands.c \
		  p_commands.c \
		  check.c \
		  modify.c \
		  sort.c \
		  utils.c \
		  stack.c \
		  error.c \
		  parsing.c \
		  free.c \
		  sorted.c

OBJS		= ${addprefix srcs/, ${SRCS:.c=.o}}

NAME		= push_swap

CC		= gcc
FLAGS		= -Wall -Wextra -Werror
ASAN		= #-fsanitize=address -g

RM		= rm -f

LIBFT		= libft.a
LIBFT_PATH	= -C inc/libft

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		${MAKE} ${LIBFT_PATH}
		${CC} ${FLAGS} ${ASAN} ${OBJS} ${LIBFT_PATH}/${LIBFT} -o ${NAME}

clean:
		${RM} ${OBJS}
		${MAKE} clean ${LIBFT_PATH}

fclean:		clean
		${RM} ${NAME}
		${MAKE} fclean ${LIBFT_PATH}

re:		fclean all

.PHONY:		all clean fclean re
