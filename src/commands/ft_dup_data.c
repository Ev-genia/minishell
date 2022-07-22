/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:43 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/21 15:49:19 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_dup_child_data(int *fd_pipe, t_cmd cmd)
{
	int	fd_in;

	close(fd_pipe[0]);
	if (cmd.flag_redir_start == 1)
	{
		fd_in = open(cmd.args_cmd[1], O_RDONLY, 0644);
		dup2(fd_in, 0);
	}
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
}

void	ft_dup_parent_data(int *fd_pipe);
