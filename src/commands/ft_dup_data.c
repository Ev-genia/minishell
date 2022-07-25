/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:43 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/25 14:41:59 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

// ./pipex[0] infile[1] "ls -l"[2] (|) cmd (|) cmd[n-2] (|) "wc -l"[n-1] outfile[n]
// 			> infile	ls -l		|	cmd	|	cmd		|	wc -l 		> outfile 

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

void	ft_dup_child_data(t_cmd cmd, int *fd_pipe)//t_cmd cmd)
{
	int	fd_in;
	int	fd_out;

	close(fd_pipe[0]);
	if (cmd.flag_heredoc_read == 1)
		ft_herdoc();
	else if (cmd.file_read == 1)
	{
		fd_in = open(cmd.file_read, O_RDONLY, 0644);
		dup2(fd_in, 0);
	}
	if (cmd.flag_pipe == 1)
	{
		dup2(fd_pipe[1], 1);
		// close(fd_pipe[1]);
	}
	if (cmd.file_write == 1)
	{
		fd_out = open(cmd.file_write, O_WRONLY + O_CREAT + O_APPEND, 0644);
		dup2(fd_out, 1);
	}

	// dup2(fd_pipe[1], 1);
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

int	ft_open_outfile()
{}

void	ft_dup_parent_data(int *fd_pipe, t_cmd cmd, pid_t pid1)
{
	int	fd_out;

	close(fd_pipe[1]);
	if (cmd.next == NULL)
	{
		waitpid(pid1, NULL, 0);
		if (cmd.file_write == 1 || cmd.flag_heredoc_write == 1)
		{
			fd_out = ft_open_outfile(cmd);
			dup2(cmd.file_write, 1);
		}
		close(fd_pipe[0]);
		ft_execve_parent();
	}
	if (cmd.file_write == 1)
	if (cmd.flag_pipe == 1)
	{
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
	}
}
