/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 12:39:33 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

int	ft_find_buitins(char *command, t_func *func, t_arr_f **choice_func)
{
	int	i;

	i = 0;
	while (ft_strncmp(command, func[i].name_func, ft_strlen(cmd)) != 0)
		i++;
	if (ft_strncmp(command, func[i].name_func, ft_strlen(cmd)) == 0)
		return (i);
	// if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
	// 	return (1);
	// if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
	// 	return (1);
	// if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
	// 	return (1);
	// if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
	// 	return (1);
	// if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
	// 	return (1);
	// if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
	// 	return (1);
	return (-1);
}

// int	ft_builtin(char **args_cmd, t_env **enpv, t_env **export)
// {
// 	int	rez;

// 	rez = -1;
// 	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
// 		rez = ft_echo(args_cmd, export, enpv);
// 	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
// 		rez = ft_env(*enpv);
// 	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
// 		rez = ft_exit(args_cmd, export, enpv);
// 	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
// 		rez = ft_export(args_cmd, export, enpv);
// 	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
// 		rez = ft_cd(args_cmd, export, enpv);
// 	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
// 		rez = ft_pwd();
// 	return (rez);
// }

int	ft_command(t_cmd cmd, t_func *func, t_arr_f **choice_func)
{
	pid_t	pid1;
	int		fd_pipe[2];
	int		rez;
	int		i;
	int		poz;
	

	rez = -1;
	if (cmd.flag_pipe == 1)
		pipe(fd_pipe);
	pid1 = fork();
	if (pid1 == 0)
	{
		if (cmd.flag_pipe == 1)
			ft_dup_child_data(fd_pipe, cmd);
		poz = ft_find_buitins(cmd.args_cmd[0], func, choice_func);
		// if (ft_find_buitins(cmd.args_cmd[0]), func, choice_func)
		if (poz > -1)
		{
			// i = 0;
			// while (ft_strncmp(cmd.args_cmd[0], func[i].name_func, ft_strlen(cmd)) != 0)
			// 	i++;
			// if (ft_strncmp(cmd.args_cmd[0], func[i].name_func, ft_strlen(cmd)) == 0)
				// rez = choice_func[func[i].type](cmd.args_cmd, &cmd.sets->enpv, &cmd.sets->export);
			rez = choice_func[func[poz].type](cmd.args_cmd, &cmd.sets->enpv, &cmd.sets->export);
			// rez = ft_builtin(cmd.args_cmd, enpv, export);
			exit(rez);
			// exit(ft_builtin(cmd.args_cmd, enpv, export));
		}
		else
			ft_execve(cmd.args_cmd[0], enpv);
	}
	else
	{
		waitpid(pid1, NULL, 0);
		if (cmd.flag_pipe == 1)
			ft_dup_parent_data(fd_pipe);
	}
	return (0);
}
