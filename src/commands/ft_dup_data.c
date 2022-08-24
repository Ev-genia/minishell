/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:43 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/23 14:21:34 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

// void	ft_first_child(int i, int *fd_pipe, t_pipe pipe_str)
// {
// 	int	fd_in;

// 	close(fd_pipe[0]);
// 	if (i == pipe_str.ac - 2)
// 		exit(1);
// 	if (i == 2)
// 	{
// 		fd_in = open(pipe_str.av[1], O_RDONLY, 0644);
// 		dup2(fd_in, STDIN_FILENO);
// 	}
// 	dup2(fd_pipe[1], 1);
// 	close(fd_pipe[1]);
// 	ft_execve(pipe_str.env, pipe_str.av[i]);
// }

int	ft_open_outfile(t_cmd cmd)
{
	int	fd;

	if (cmd.flag_heredoc_write == 1)
		fd = open(cmd.file_write, O_WRONLY + O_APPEND + O_CREAT, 0644);
	else
		fd = open(cmd.file_write, O_WRONLY + O_TRUNC + O_CREAT, 0644);
	return (fd);
}

void	ft_dup_child_data(t_cmd cmd, int *fd_pipe)
{
	int	fd_in;
	int	fd_out;

	if (cmd.flag_heredoc_read == 1)
		ft_herdoc(cmd);
	else if (cmd.flag_redir_read == 1)
	{
		fd_in = open(cmd.file_read, O_RDONLY, 0644);
		dup2(fd_in, 0);
		close(fd_in);
	}
	if (cmd.flag_redir_write == 1 || cmd.flag_heredoc_write == 1)
	{
		fd_out = ft_open_outfile(cmd);
		dup2(fd_out, 1);
		close(fd_out);
		return ;
	}
	// dup2(fd_pipe[1], 1);
	dup2(fd_pipe[1], cmd.sets->start_fd_out);
	close(fd_pipe[1]);
}

// void	ft_parent_proc(int i, int *fd_pipe, int pid, t_pipe pipe_str)
// {
// 	int	fd_out;

// 	close(fd_pipe[1]);
// 	if (i == pipe_str.ac - 2)
// 	{
// 		waitpid(pid, NULL, 0);
// 		fd_out = ft_open_outfile(pipe_str.ac, pipe_str.av);
// 		dup2(fd_out, STDOUT_FILENO);
// 		close(fd_out);
// 		close(fd_pipe[0]);
// 		ft_execve(pipe_str.env, pipe_str.av[pipe_str.ac - 2]);
// 	}
// 	dup2(fd_pipe[0], 0);
// 	close(fd_pipe[0]);
// }

// int	ft_open_outfile(int ac, char **av)
// {
// 	int	fd;

// 	if (ft_strncmp(av[1], "here_doc", 8) == 0)
// 		fd = open(av[ac - 1], O_WRONLY + O_APPEND + O_CREAT, 0644);
// 	else
// 		fd = open(av[ac - 1], O_WRONLY + O_TRUNC + O_CREAT, 0644);
// 	return (fd);
// }

void	ft_dup_read_write(t_cmd cmd)
{
	int	fd_out;
	int	fd_in;

	if (cmd.flag_heredoc_read == 1)
		ft_herdoc(cmd);
	else if (cmd.flag_redir_read == 1)
	{
		fd_in = open(cmd.file_read, O_RDONLY, 0644);
		dup2(fd_in, 0);
		close(fd_in);
	}
	if (cmd.flag_redir_write == 1 || cmd.flag_heredoc_write == 1)
	{
		fd_out = ft_open_outfile(cmd);
		dup2(fd_out, 1);
		close(fd_out);
	}
	// else
	// 	dup2(cmd.sets->start_fd_out, 1);
}

void	ft_ctrl_c_parent(int sign)
{
	(void)sign;
	return ;
}

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
ft_putstr_fd("\nlast command: ", 1);
ft_putstr_fd(cmd.lst_args->content, 1);
ft_putstr_fd("\n", 1);
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
		}
		return (-1);
	}
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
	return (0);
}
