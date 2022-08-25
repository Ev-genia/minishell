/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:42:25 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/25 11:42:19 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

// void	pipex_heredoc(char **argv)
// {
// 	pid_t	pid1;
// 	int		fd_pipe[2];

// 	if (pipe(fd_pipe) == -1)
// 		ft_perror("Pipe error");
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		ft_perror("Pipe error");
// 	if (pid1 == 0)
// 		ft_child_h_d(argv, fd_pipe);
// 	else
// 	{
// 		close(fd_pipe[1]);
// 		dup2(fd_pipe[0], 0);
// 		close(fd_pipe[0]);
// 		if (waitpid(pid1, NULL, 0) == -1)
// 			ft_perror("Error of terminated 1 child process");
// 	}
// }

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
}

// void	ft_child_h_d(char **argv, int *fd_pipe)
// {
// 	char	*term_str;
// 	char	*stop;

// 	close(fd_pipe[0]);
// 	stop = ft_strjoin(argv[2], "\n");
// 	write(0, "pipex here_doc> ", 16);
// 	term_str = get_next_line(0);
// 	while (term_str != NULL && ft_strncmp(term_str, stop, ft_strlen(stop)) != 0)
// 	{
// 		ft_putstr_fd(term_str, fd_pipe[1]);
// 		free(term_str);
// 		write(0, "pipex here_doc> ", 16);
// 		term_str = get_next_line(0);
// 	}
// 	if (term_str != NULL)
// 		free(term_str);
// 	free(stop);
// 	exit(0);
// }

void	ft_child_h_d(int *fd_pipe, t_cmd *cmd)
{
	char	*str;

	dup2(cmd->sets->start_fd_in, 0);
	close(fd_pipe[0]);
	str = readline("\033[36m>\033[0m ");
	while (str != NULL
		&& ft_strncmp(str, cmd->limiter, ft_strlen(cmd->limiter)) != 0)
	{
		ft_putstr_fd(str, fd_pipe[1]);
		ft_putstr_fd("\n", fd_pipe[1]);
		free(str);
		str = readline("\033[36m>\033[0m ");
	}
	if (str != NULL)
		free(str);
	exit(0);
}

void	ft_herdoc(t_cmd *cmd)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
		ft_child_h_d(fd_pipe, cmd);
	else if (pid > 0)
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
		if (waitpid(pid, NULL, 0) == -1)
			ft_perror("error of terminated 1 child process");
	}
	else
		ft_perror("pipe error");
}
