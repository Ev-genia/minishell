/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/15 16:50:28 by mlarra           ###   ########.fr       */
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

typedef struct s_env //связный список для парсинга переменной окружения
{
	char			*key;
	char			*value;
	int				flag_key;
	struct s_env	*next;
}	t_env;

//lst_env.c
t_env	*ft_lstnew_env(char *content1, char *content2, int flag);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);

//ft_env.c
void	ft_env(t_env *env);
t_env	*ft_env_struct(char **ev);
char	*ft_find_env(char *env, char c);

//ft_pwd.c
int		ft_pwd(void);

//ft_echo.c
void	ft_echo(char **arg);

//ft_export.c
t_env	*ft_sorted_export(t_env *ev);
t_env	*ft_export(char **arg, t_env *export);
int		ft_arr_len(char **arr);
void	ft_no_valid_command(char *str, char *name_command);
int		ft_check_arg_export(char *s);

//ft_sort_export.c
t_env	*ft_sorted_export(t_env *list);
int		ft_max_len(char *s1, char *s2);

//ft_add_to_export.c
void	ft_add_to_export(t_env **export, char *s);

//ft_unset.c
int		ft_unset(char **arg, t_env **env, t_env **export);

//=================parser.c========================//
int		ft_parse(char **av, t_env *env_list);

#endif
