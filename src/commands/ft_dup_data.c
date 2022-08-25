/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:43 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/25 11:49:24 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_open_outfile(t_cmd *cmd)
{
	ft_close(cmd->fd_out);
	if (cmd->flag_heredoc_write == 1)
		cmd->fd_out = open(cmd->file_write, O_WRONLY + O_APPEND + O_CREAT, 0700);
	else
		cmd->fd_out = open(cmd->file_write, O_WRONLY + O_TRUNC + O_CREAT, 0700);
	if (cmd->fd_out == -1)
	{
		ft_putstr_fd("\033[36m(→_→)$\033[0m ", 2);
		ft_putstr_fd(cmd->file_write, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_code = 1;
		return ;
	}
	dup2(cmd->fd_out, STDOUT_FILENO);
}

/*
int	ft_dup_parent_data(int *fd_pipe, t_cmd cmd, pid_t pid1)
{
	int	poz;
	int	rez;
// ft_putstr_fd("\nstart ft_dup_parent_data\n", 1);
	// signal(SIGINT, ft_ctrl_c_parent);
	close(fd_pipe[1]);
// ft_putstr_fd("\nft_dup_parent_data, command: ", 1);
// ft_putstr_fd(cmd.lst_args->content, 1);
// ft_putstr_fd("\n", 1);
	if (cmd.next == NULL || ft_lstsize_cmd(cmd.sets->lst_cmds) == 1)
	{
		signal(SIGTSTP, SIG_DFL);
// ft_putstr_fd("\nlast command: ", 1);
// ft_putstr_fd(cmd.lst_args->content, 1);
// ft_putstr_fd("\n", 1);
// ft_putstr_fd("\nft_dup_parent_data, 1 if\n", 1);
		(void)pid1;

		// waitpid(pid1, NULL, 0);
		ft_dup_read_write(cmd);
		poz = ft_find_buitins((char *)cmd.lst_args->content, cmd.sets->func);
// ft_putstr_fd("\npoz: ", 1);
// ft_putnbr_fd(poz, 1);
// ft_putstr_fd("\n", 1);
		if (poz > -1)
		{
// ft_putstr_fd("\nft_dup_parent_data, if poz > -1\n", 1);
			rez = cmd.sets->choice_func[cmd.sets->func[poz].type](cmd.lst_args,
					&cmd.sets->enpv, &cmd.sets->export);
			return (rez);
		}
		else
		{
// ft_putstr_fd("\nft_dup_parent_data, ft_execve\n", 1);
			ft_execve(cmd, cmd.sets->enpv);
ft_putstr_fd("\nTEST ft_execve\n", 1);			
			return (-1);
		}
	}
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
	return (0);
}
*/
