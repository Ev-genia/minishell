/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/14 23:22:07 by mlarra           ###   ########.fr       */
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
t_env	*ft_lstnew_env(char *content1, char *content2);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);

//ft_env.c
void	ft_env(t_env *env);
t_env	*ft_env_struct(char **ev);

//ft_pwd.c
int		ft_pwd(void);

//ft_echo.c
void	ft_echo(char **arg);

//ft_export.c
t_env	*ft_sorted_export(t_env *ev);
void	ft_export(char **arg, t_env *export);

//ft_sort_export.c
t_env	*ft_sorted_export(t_env *list);

//=================parser.c========================//
int		ft_parse(char **av, t_env *env_list);

#endif
