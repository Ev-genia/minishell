# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:01:49 by mlarra            #+#    #+#              #
#    Updated: 2022/09/13 19:15:37 by wcollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIB_DIR	=	./src/libft/

DIR				=	./src/
DIR_BUILTINS	=	./src/builtins/
DIR_PARSER		=	./src/parser/
DIR_COMMAND		=	./src/commands/
DIR_INIT		=	./src/init/
# DIR_TERM		=	./src/term_caps/
DIR_SIGNALS		=	./src/signals/

DIR_HEADER	=	./includes

READLINE_L		=	-L /usr/local/Cellar/readline/8.1.2/lib
READLINE_I		=	-I /usr/local/Cellar/readline/8.1.2/include

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

DIR_DOLL_QUEST	=	${addprefix ${DIR_BUILTINS},dollar_question/}
SRC_DOLL_QUEST	=	${addprefix ${DIR_DOLL_QUEST}, ft_dollar_question.c}

SRC_COMMAND	=	${addprefix ${DIR_COMMAND}, ft_command.c ft_dup_data.c\
		ft_execve.c	ft_herdoc.c	ft_convert_to_arr.c	ft_execve_utils.c\
		ft_t_cmd_utils.c	ft_shell.c	ft_fds.c	ft_minipipe.c	ft_exec.c}

SRC_INIT	=	${addprefix ${DIR_INIT}, ft_init_arr_func.c ft_init_set.c}

SRC_PARSER	=	${addprefix ${DIR_PARSER}, parser.c preparser.c lst_cmd_operations.c pars_utils.c}

# SRC_TERM	=	${addprefix ${DIR_TERM}, ft_term_caps.c}

SRC_SIGNALS	=	${addprefix ${DIR_SIGNALS}, ft_signal_init.c}# ft_handler.c}

SRC		=	${DIR}main.c\
			${SRC_PWD}\
			${SRC_ENV}\
			${SRC_ECHO}\
			${SRC_EXPORT}\
			${SRC_UNSET}\
			${SRC_CD}\
			${SRC_EXIT}\
			${SRC_INIT}\
			${SRC_COMMAND}\
			${SRC_PARSER}\
			${SRC_SIGNALS}\
			${SRC_DOLL_QUEST}

HEADER	=	${addprefix ${DIR_HEADER}/,minishell.h}

OBJ		=	${SRC:%.c=%.o}

CFLAGS	=	-g -Wall -Wextra -Werror 

CC		=	cc

RM		=	rm -f

.PHONY	:	all	clean	fclean	re	bonus	norm

%.o	:	%.c	${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ}
	make -C ${LIB_DIR}
	make bonus -C ${LIB_DIR}
	${CC} ${CFLAGS} -I${HEADER} $^ -L ${LIB_DIR} -lft -ltermcap -lreadline ${READLINE_L} ${READLINE_I} -lncurses -o $@

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