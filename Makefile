# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:01:49 by mlarra            #+#    #+#              #
#    Updated: 2022/07/12 12:01:52 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

DIR		=	./src/
DIR_BUILTINS	=	./src/builtins/

DIR_HEADER	=	./includes

DIR_PWD	=	${addprefix ${DIR_BUILTINS},pwd/}
SRC_PWD	=	${addprefix ${DIR_PWD}, ft_pwd.c}

DIR_ENV	=	${addprefix ${DIR_BUILTINS},env/}
SRC_ENV	=	${addprefix ${DIR_ENV}, ft_env.c lst_env.c}

SRC		=	${DIR}main.c\
			${SRC_PWD}\
			${SRC_ENV}

HEADER	=	${addprefix ${DIR_HEADER}/,minishell.h}

OBJ		=	${SRC:%.c=%.o}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f

.PHONY	:	all	clean	fclean	re	bonus	norm

%.o	:	%.c	${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ}
	${CC} ${CFLAGS} -I${HEADER} $^ -o $@

all		:	${NAME}

clean	:
	${RM} ${OBJ}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

norm	:
	norminette ${SOURCES} ${HEADER}