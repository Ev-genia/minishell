/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/21 00:04:31 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
// # include "libft/libft.h"
# include "../src/libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>

typedef struct s_env //связный список для парсинга переменной окружения
{
	char			*key;
	char			*value;
	int				flag_key;
	struct s_env	*next;
}	t_env;

int	g_exit_code;

//lst_env.c
t_env	*ft_lstnew_env(char *content1, char *content2, int flag);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);

//ft_env.c
int		ft_env(t_env *env);
t_env	*ft_env_struct(char **ev);
char	*ft_find_env(char *env, char c);

//ft_pwd.c
int		ft_pwd(void);

//ft_echo.c
int		ft_echo(char **arg);

//ft_export.c
int		ft_export(char **arg, t_env **export, t_env **env);
int		ft_arr_len(char **arr);
void	ft_no_valid_command(char *str, char *name_command, char *message);
int		ft_check_arg_export(char *s);

//ft_sort_export.c
t_env	*ft_sorted_export(t_env *list);
int		ft_max_len(char *s1, char *s2);
t_env	*ft_copy_env(t_env *list);

//ft_add_to_export.c
void	ft_add_to_export(t_env **export, char *s);
int		ft_find_position(t_env *list, char *key);

//lst_export.c
void	ft_lstclear_env(t_env **lst);

//ft_add_to_env.c
void	ft_add_to_env(t_env **list, char *s);

//ft_unset.c
int		ft_unset(char **arg, t_env **env, t_env **export);
int		ft_find_key_id(char *key, t_env *list);

//ft_cd.c
int		ft_cd(char **args, t_env **enpv, t_env **export);

//ft_exit.c
int		ft_exit(char **args);

// //ft_print_promt.c
//void	ft_print_promt(void);

//=================parser.c========================//
int		ft_parse(char *str, t_env *env_list);

//=================parser.c========================//
int		ft_parse(char *str, t_env *env_list);

#endif
