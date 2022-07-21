/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/21 13:32:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_find_buitins(char *cmd)
{
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (1);
	return (0);
}

int	ft_builtin(char **args_cmd, t_env **enpv, t_env **export)
{
	int	rez;

	rez = -1;
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		rez = ft_echo(args_cmd);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		rez = ft_env(*enpv);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		rez = ft_exit(args_cmd);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		rez = ft_export(args_cmd, export, enpv);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		rez = ft_cd(args_cmd, enpv, export);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		rez = ft_pwd();
	return (rez);
}

int	ft_command(t_cmd cmd, t_env **enpv, t_env **export)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == 0)
	{
		if (cmd.flag_pipe == 1)
			ft_dup_child_data();
		if (ft_find_buitins(cmd.args_cmd[0]))
			ft_builtin(cmd.args_cmd, enpv, export);
		else
			ft_execve(cmd.args_cmd[0], enpv);
	}
	else
	{
		waitpid(pid1, NULL, 0);
		if (cmd.flag_pipe == 1)
			ft_dup_parent_data();
	}
	return (0);
}
