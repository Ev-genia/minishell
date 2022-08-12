/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:47:33 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/12 16:06:42 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_replace_line(int exit_code)
{
	// rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_code = exit_code;
}

void	ft_handler(int sign)
{
	pid_t	pid;

	pid = waitpid(-1, 0, WNOHANG);
	if (sign == SIGINT)
	{
		if (pid == -1)
		{
			write(1, "  \n", 3);
			ft_replace_line(1);
		}
		else
			ft_signal_ctrl_c(2);
	}
	else if (sign == SIGQUIT && pid != -1)
		ft_signal_quit(3);
	else
		ft_replace_line(128 + 3);
}
