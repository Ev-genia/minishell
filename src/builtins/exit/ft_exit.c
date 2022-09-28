/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:10:08 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/28 16:52:55 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_check_arg_exit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			return (1);
	return (0);
}

int	ft_arg_not_num(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit(255);
	return (255);
}

int	ft_too_many_arg(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: too many arguments\n", 2);
	return (1);
}

int	ft_exit(t_list *lst_args, t_env **export, t_env **env)
{
	int		len;
	int		nbr;
	t_list	*list;

	(void)export;
	(void)env;
	list = lst_args;
	len = ft_lstsize(list);
	ft_putendl_fd("exit", 2);
	if (len == 1)
		exit(0);
	if (len > 2)
		return (ft_too_many_arg());
	if (ft_check_arg_exit((char *)list->next->content))
		return (ft_arg_not_num((char *)list->next->content));
	nbr = ft_atoi((char *)list->next->content);
	exit(nbr);
	return (0);
}
