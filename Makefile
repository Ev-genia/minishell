# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:01:49 by mlarra            #+#    #+#              #
#    Updated: 2022/07/12 16:58:42 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT	=	libft.a
LIB_DIR	=	./src/libft/
LIB_NAME	=	./src/libft/libft.a

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
	make -C ${LIB_DIR}
	${CC} ${CFLAGS} -I${HEADER} $^ -L ${LIB_DIR} -lft -o $@

# ${LIB_NAME}	:
# 	${MAKE} -C ${LIB_DIR}

# all		:	${LIB_NAME} ${NAME}
all		:	${NAME}

clean	:
	${RM} ${OBJ}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

norm	:
	norminette ${SOURCES} ${HEADER}