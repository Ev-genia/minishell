/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:16:58 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 10:14:38 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_echo(char **arg, t_env **export, t_env **env)
{
	int	i;

	(void)export;
	(void)env;
	i = 1;
	if (ft_strncmp(arg[i], "-n", 2) == 0)
		ft_putstr_fd(arg[++i], 1);
	else
	{
		ft_putstr_fd(arg[i], 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
