# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dareias- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 11:36:30 by dareias-          #+#    #+#              #
#    Updated: 2020/12/14 11:38:06 by dareias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_init_chars.c ft_stdin.c ft_find_solution.c ft_print_solution.c ft_basic_atoi.c ft_map_error.c ft_strlen.c ft_file_to_str.c ft_save_map.c ft_validity.c ft_map_to_arr.c ft_sanitize.c ft_is_printable.c main.c

OBJS	= ${SRCS:.c=.o}

DEPS	= ft_bsq.h

NAME	= bsq

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

RM		= rm -f

${NAME}:	${DEPS} ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
