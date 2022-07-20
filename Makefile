# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:01:49 by mlarra            #+#    #+#              #
#    Updated: 2022/07/20 16:58:49 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIB_DIR	=	./src/libft/

DIR				=	./src/
DIR_BUILTINS	=	./src/builtins/
DIR_PARSER		=	./src/parser/
DIR_PROMT		=	./src/promt/

DIR_HEADER	=	./includes

DIR_PWD	=	${addprefix ${DIR_BUILTINS},pwd/}
SRC_PWD	=	${addprefix ${DIR_PWD}, ft_pwd.c}

DIR_ENV	=	${addprefix ${DIR_BUILTINS},env/}
SRC_ENV	=	${addprefix ${DIR_ENV}, ft_env.c lst_env.c}

DIR_ECHO	=	${addprefix ${DIR_BUILTINS},echo/}
SRC_ECHO	=	${addprefix ${DIR_ECHO}, ft_echo.c}

DIR_EXPORT	=	${addprefix ${DIR_BUILTINS},export/}
SRC_EXPORT	=	${addprefix ${DIR_EXPORT}, ft_export.c ft_sort_export.c\
		ft_add_to_export.c	ft_add_to_env.c	lst_export.c}

DIR_UNSET	=	${addprefix ${DIR_BUILTINS},unset/}
SRC_UNSET	=	${addprefix ${DIR_UNSET}, ft_unset.c}

DIR_CD	=	${addprefix ${DIR_BUILTINS},cd/}
SRC_CD	=	${addprefix ${DIR_CD}, ft_cd.c}

DIR_EXIT	=	${addprefix ${DIR_BUILTINS},exit/}
SRC_EXIT	=	${addprefix ${DIR_EXIT}, ft_exit.c}

SRC		=	${DIR}main.c\
			${SRC_PWD}\
			${SRC_ENV}\
			${SRC_ECHO}\
			${SRC_EXPORT}\
			${SRC_UNSET}\
			${SRC_CD}\
			${SRC_EXIT}\
			${DIR_PARSER}parser.c\
			${DIR_PROMT}ft_print_promt.c

HEADER	=	${addprefix ${DIR_HEADER}/,minishell.h}

OBJ		=	${SRC:%.c=%.o}

CFLAGS	=	-Wall -Wextra -Werror -g

CC		=	cc

RM		=	rm -f

.PHONY	:	all	clean	fclean	re	bonus	norm

%.o	:	%.c	${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ}
	make -C ${LIB_DIR}
	${CC} ${CFLAGS} -I${HEADER} $^ -L ${LIB_DIR} -lft -ltermcap -o $@

# ${LIB_NAME}	:
# 	${MAKE} -C ${LIB_DIR}

# all		:	${LIB_NAME} ${NAME}
all		:	${NAME}

clean	:
	${RM} ${OBJ}
	make -C ${LIB_DIR} clean

fclean	:	clean
	${RM} ${NAME}
	make -C ${LIB_DIR} fclean

re		:	fclean all

norm	:
	norminette ${SOURCES} ${HEADER}