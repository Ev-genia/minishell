/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minipipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:19:56 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/27 10:46:00 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_input(t_cmd *cmd)
{
	ft_close(cmd->fd_in);
	if (cmd->flag_heredoc_read)
		ft_herdoc(cmd);
	else
	{
		cmd->fd_in = open(cmd->file_read, O_RDONLY, 0700);
		if (cmd->fd_in == -1)
		{
			ft_putstr_fd("\033[36m(→_→)$\033[0m ", 2);
			ft_putstr_fd(cmd->file_read, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			g_exit_code = 1;
			return ;
		}
		dup2(cmd->fd_in, STDIN_FILENO);
	}
}

int	ft_minipipe(t_cmd *cmd)
{
	pid_t	pid;
	int		fds[2];

	pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		ft_close(fds[0]);
		close(STDOUT_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		// cmd->fd_pipout = fds[1];
		ft_close(fds[1]);
		cmd->pid = -1;
		return (2);
	}
	else
	{
		close(STDIN_FILENO);
		dup2(fds[0], STDIN_FILENO);
		// cmd->fd_pipin = fds[0];
		ft_close(fds[0]);
		ft_close(fds[1]);
		cmd->pid = pid;
		return (1);
	}
}
