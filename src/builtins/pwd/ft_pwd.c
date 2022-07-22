/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:32:35 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 10:19:34 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_pwd(char **args, t_env **export, t_env **env)
{
	char	*pwd;

	(void)args;
	(void)export;
	(void)env;
	pwd = getcwd(NULL, 1024);
	if (!pwd)
	{
		perror("pwd error");
		return (1);
	}
	ft_putstr_fd(pwd, 1);
	write(1, "\n", 1);
	free(pwd);
	return (0);
}
