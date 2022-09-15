/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:08:08 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/14 16:17:40 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

int	ft_magic_exec(t_cmd *cmd, char *path)
{
	int	rez;

	rez = 0;
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		execve(path, cmd->cmd_arr, cmd->sets->env_arr);
	}
	else
		waitpid(cmd->pid, &rez, 0);
	
	return (rez);
}

int	ft_exec_bin(t_cmd *cmd)
{
	int		rez;
	// char	**bin;
	char	*path;
int	i;
int	len;

i = -1;
len = ft_arr_len(cmd->cmd_arr);
ft_putstr_fd("cmd_arr:\n", 1);
while (++i < len)
{
	ft_putstr_fd(cmd->cmd_arr[i], 1);
	ft_putstr_fd("\n", 1);
}


	rez = 127;
ft_putstr_fd("command_ft_exec_bin: ", 1);
ft_putstr_fd((char *)cmd->lst_args->content, 1);
ft_putstr_fd("\n", 1);
	path = ft_get_path((char *)cmd->lst_args->content, cmd->sets->enpv);
// printf("path_ft_exec_bin: %s for command: |%s|\n", path, (char *)cmd->lst_args->content);

	if (!path)
	{
		ft_write((char *)cmd->lst_args->content);
// printf("enter_to_!path_ft_exec_bin for command: |%s|\n", (char *)cmd->lst_args->content);
ft_putstr_fd("enter_to_!path_ft_exec_bin for command: ", 1);
ft_putstr_fd(cmd->lst_args->content, 1);
ft_putstr_fd("\n", 1);
		// free(lst?);
		// exit(rez);
		return (rez);
	}
	while (cmd->sets->enpv && cmd->sets->enpv->value 
		&& ft_strncmp(cmd->sets->enpv->value, "PATH=", 5) != 0)
		cmd->sets->enpv = cmd->sets->enpv->next;
	cmd->cmd_arr = ft_convert_to_arr_list(cmd->lst_args);
	cmd->sets->env_arr = ft_convert_to_arr_env(cmd->sets->enpv);
	if (cmd->sets->enpv == NULL || cmd->sets->enpv->next == NULL)
		return (ft_magic_exec(cmd, path));
	
	// bin = ft_split(cmd->sets->enpv->value, ':');
	// if (!cmd->cmd_arr[0] || !bin[0])
	// 	return (1);


	return (rez);
}

void	ft_exec_cmd(t_cmd *cmd)
{
	int	poz;

	// if (cmd->charge == 0)
	// 	return ;
ft_putstr_fd("command_ft_exec_cmd: ", 1);
ft_putstr_fd((char *)cmd->lst_args->content, 1);
ft_putstr_fd("\n", 1);
	cmd->cmd_arr = ft_convert_to_arr_list(cmd->lst_args);
	poz = ft_find_buitins((char *)cmd->lst_args->content, cmd->sets->func);
	if (cmd->cmd_arr
		&& ft_strncmp(cmd->cmd_arr[0], "exit", ft_strlen("exit")) == 0
		&& cmd->flag_pipe == 0)
		ft_exit(cmd->lst_args, &cmd->sets->export, &cmd->sets->enpv);
	else if (cmd->cmd_arr && poz > -1)
		g_exit_code = cmd->sets->choice_func[cmd->sets->func[poz].type](cmd->lst_args,
				&cmd->sets->enpv, &cmd->sets->export);
	else if (cmd->cmd_arr)
		g_exit_code = ft_exec_bin(cmd);
	ft_free_arr(cmd->cmd_arr);
	ft_close(cmd->fd_pipin);
	ft_close(cmd->fd_pipout);
	cmd->fd_pipin = -1;
	cmd->fd_pipout = -1;
	cmd->charge = 0;
}
