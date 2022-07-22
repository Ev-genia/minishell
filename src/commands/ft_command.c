/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 15:27:51 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

int	ft_find_buitins(char *command, t_func *func)
{
	int	i;

	i = 0;
	while (ft_strncmp(command, func[i].name_func, ft_strlen(command)) != 0)
		i++;
	if (ft_strncmp(command, func[i].name_func, ft_strlen(command)) == 0)
		return (i);
	return (-1);
}

int	ft_command(t_cmd cmd, t_func *func, t_arr_f choice_func)
{
	pid_t	pid1;
	int		fd_pipe[2];
	int		rez;
	int		poz;
	

	rez = -1;
	if (cmd.flag_pipe == 1)
		pipe(fd_pipe);
	pid1 = fork();
	if (pid1 == 0)
	{
		if (cmd.flag_pipe == 1)
			ft_dup_child_data(fd_pipe, cmd);
		poz = ft_find_buitins(cmd.args_cmd[0], func);
		if (poz > -1)
		{
			rez = choice_func[func[poz].type](cmd.args_cmd, &cmd.sets->enpv, &cmd.sets->export);
			exit(rez);
		}
		else
			ft_execve(cmd.args_cmd[0], enpv);
	}
	else
	{
		// waitpid(pid1, NULL, 0);
		if (cmd.flag_pipe == 1)
			ft_dup_parent_data(fd_pipe);
	}
	return (0);
}
