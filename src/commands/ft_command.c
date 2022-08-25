/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/25 16:02:20 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

char	*ft_tolower_str(char *s)
{
	int		i;
	int		len;
	char	*str;

	i = -1;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	while (++i < len)
		str[i] = ft_tolower(s[i]);
	str[i] = '\0';
	// free(s);
	return (str);
}

int	ft_arr_func_len(t_func *arr)
{
	int	i;

	i = 0;
	while (arr[i].name_func != NULL)
		i++;
	return (i);
}

int	ft_find_buitins(char *command, t_func *func)
{
	int	i;
	int	len;

	i = 0;
	command = ft_tolower_str(command);
	len = ft_arr_func_len(func);
	while (i < len)
	{
		if (ft_strncmp(command, func[i].name_func, ft_strlen(command)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
/*
int	ft_child_process(t_cmd cmd, t_func *func, t_arr_f choice_func,
	int *fd_pipe)
{
	int		poz;
	int		rez;
// ft_putstr_fd("\nenter to ft_child_process\n", 1);
// ft_putstr_fd(cmd.lst_args->content, 1);
// ft_putstr_fd("\n", 1);
	close(fd_pipe[0]);
	if (cmd.next == NULL || ft_lstsize_cmd(cmd.sets->lst_cmds) == 1)
	{
// ft_putstr_fd("\nft_child_process, exit\n", 1);	
// ft_putstr_fd(cmd.lst_args->content, 1);
// ft_putstr_fd("\n", 1);	
		exit(0);
	}
	if (cmd.flag_pipe || cmd.flag_heredoc_read || cmd.flag_heredoc_write
		|| cmd.flag_redir_read || cmd.flag_redir_write)
		ft_dup_child_data(cmd, fd_pipe);
	poz = ft_find_buitins((char *)cmd.lst_args->content, func);
	if (poz > -1)
	{
// ft_putstr_fd("\npoz > -1\n", 1);
		rez = choice_func[func[poz].type](cmd.lst_args,
				&cmd.sets->enpv, &cmd.sets->export);
		exit(rez);
	}
	else
{
// ft_putstr_fd("\nchild_cat\n", 1);
// dup2(cmd.sets->start_fd_in, 0);
		// signal(SIGINT, ft_signal_ctrl_c_child);
		ft_execve(cmd, cmd.sets->enpv);
}
	return (-1);
}
*/
/*
int	ft_command(t_cmd cmd)
{
	pid_t	pid1;
	int		fd_pipe[2];
	int		rez;

// ft_putstr_fd("ft_command, command: ", 1);
// ft_putstr_fd(cmd.lst_args->content, 1);
// ft_putstr_fd("\n", 1);

	if (cmd.flag_pipe == 1)
		pipe(fd_pipe);
	pid1 = fork();
	signal(SIGINT, SIG_IGN);
	// signal(SIGINT, SIG_DFL);
	if (pid1 == 0)
	{
// ft_putstr_fd("\nft_command, pid1 == 0\n", 1);
// ft_putstr_fd("\npid1_child: ", 1);
// ft_putnbr_fd(pid1, 1);
// ft_putstr_fd("\n", 1);	
		signal(SIGINT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGQUIT, ft_signal_ctrl_d);
		// signal(SIGINT, ft_signal_ctrl_c_child);
		// signal(SIGQUIT, ft_signal_quit);
		rez = ft_child_process(cmd, cmd.sets->func, cmd.sets->choice_func, fd_pipe);
	}
	else
	{
// ft_putstr_fd("\nft_command, pid1 > 0\n", 1);
// ft_putstr_fd("\npid1_parent: ", 1);
// ft_putnbr_fd(pid1, 1);
// ft_putstr_fd("\n", 1);		
		// ft_signal_init();
		
		rez = ft_dup_parent_data(fd_pipe, cmd, pid1);
	}
	return (rez);
}
*/
// /*
void	ft_command(t_cmd *cmd)
{
	int	pipe;

	pipe = 0;
	if (cmd->flag_redir_write || cmd->flag_heredoc_write)
		ft_open_outfile(cmd);
	if (cmd->flag_redir_read || cmd->flag_heredoc_read)
		ft_input(cmd);
	if (cmd->flag_pipe)
		pipe = ft_minipipe(cmd);
	// if (cmd->flag_pipe && cmd->next && pipe != 1)
	// 	ft_command(cmd->next);
	if (pipe != 1)
		ft_exec_cmd(cmd);
}
// */
