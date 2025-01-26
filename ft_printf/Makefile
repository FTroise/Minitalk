# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:15:55 by ftroise           #+#    #+#              #
#    Updated: 2024/02/25 13:09:49 by ftroise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c \
		ft_printf.c \

SRCBONUS = printf_utils.c \
		ft_printf.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

bonus : ${NAME}
	gcc -c ${FLAGS} ${SRCBONUS}
	ar rcs ${NAME} ${OBJBONUS}


clean:
	${RM} ${OBJS} ${OBJBONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all
