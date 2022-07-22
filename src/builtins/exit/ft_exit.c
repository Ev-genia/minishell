/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:10:08 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 10:16:56 by mlarra           ###   ########.fr       */
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

int	ft_exit(char **args, t_env **export, t_env **env)
{
	int	len;
	int	nbr;

	(void)export;
	(void)env;
	len = ft_arr_len(args);
	if (len == 1)
		exit(0);
	if (len > 2)
		return (ft_too_many_arg());
	if (ft_check_arg_exit(args[1]))
		return (ft_arg_not_num(args[1]));
	nbr = ft_atoi(args[1]);
	exit(nbr);
	return (0);
}
