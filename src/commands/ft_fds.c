/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:10:28 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/24 17:26:50 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_close_fds(t_cmd *cmd)
{
	ft_close(cmd->fd_in);
	ft_close(cmd->fd_out);
	ft_close(cmd->fd_pipin);
	ft_close(cmd->fd_pipout);
}

void	ft_reset_std(t_set *set)
{
	dup2(set->start_fd_in, STDIN_FILENO);
	dup2(set->start_fd_out, STDOUT_FILENO);
}

void	ft_reset_fds(t_cmd *cmd)
{
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->fd_pipin = -1;
	cmd->fd_pipout = -1;
	cmd->pid = -1;
}
