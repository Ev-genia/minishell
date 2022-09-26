/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:08:08 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/23 15:24:23 by mlarra           ###   ########.fr       */
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
printf("ft_magic_exec cmd->cmd_arr[0]: %s\n", cmd->cmd_arr[0]);
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
// ft_putstr_fd("cmd_arr:\n", 1);
printf("ft_exec_bin cmd_arr:\n");
while (++i < len)
{
	// ft_putstr_fd(cmd->cmd_arr[i], 1);
	// ft_putstr_fd("\n", 1);
	printf("%s\n", cmd->cmd_arr[i]);
}


	rez = 127;
// ft_putstr_fd("command_ft_exec_bin: ", 1);
// ft_putstr_fd((char *)cmd->lst_args->content, 1);
// ft_putstr_fd("\n", 1);
// printf("command_ft_exec_bin: %s\n",(char *)cmd->lst_args->content);
	path = ft_get_path((char *)cmd->lst_args->content, cmd->sets->enpv);
printf("path_ft_exec_bin: %s for command: |%s|\n", path, (char *)cmd->lst_args->content);

	if (!path)
	{
		ft_write((char *)cmd->lst_args->content);
printf("enter_to_!path_ft_exec_bin for command: |%s|\n", cmd->cmd_arr[0]);
// ft_putstr_fd("enter_to_!path_ft_exec_bin for command: ", 1);
// ft_putstr_fd(cmd->lst_args->content, 1);
// ft_putstr_fd("\n", 1);
		// free(lst?);
		// exit(rez);
		return (rez);
	}
// t_env	*env_copy = cmd->sets->enpv;

// 	while (cmd->sets->enpv && cmd->sets->enpv->value 
// 		&& ft_strncmp(cmd->sets->enpv->key, "PATH", 4) != 0)
// {
// printf("ft_exec_bin %s=%s\n", cmd->sets->enpv->key, cmd->sets->enpv->value);
// 		cmd->sets->enpv = cmd->sets->enpv->next;
// }
// 	// cmd->cmd_arr = ft_convert_to_arr_list(&cmd->lst_args);
	cmd->sets->env_arr = ft_convert_to_arr_env(cmd->sets->enpv);
int	j = 0;
int	len_i = ft_arr_len(cmd->sets->env_arr);
printf("len_i:%d\n", len_i);
// printf("ft_exec_bin cmd->sets->env_arr[%d]: %s\n", j, cmd->sets->env_arr[j]);
while (j < len_i)
{
printf("ft_exec_bin cmd->sets->env_arr[%d]: %s\n", j, cmd->sets->env_arr[j]);
// ft_putendl_fd("ft_exec_bin cmd->sets->env_arr[j]: ", 1);
// ft_putendl_fd(cmd->sets->env_arr[j], 1);
// ft_putendl_fd("\n", 1);
j++;
}
	// if (cmd->sets->enpv == NULL || cmd->sets->enpv->next == NULL)
// {
printf("return ft_magic_exec command: %s\n", cmd->cmd_arr[0]);
		return (ft_magic_exec(cmd, path));
// }
	
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
// ft_putendl_fd("ft_exec_cmd cmd->lst_args->content: ", 1);
t_list	*tmp = cmd->lst_args;
// while (tmp)
// {
	printf("|%s|\n", (char *)tmp->content);
// 	tmp = tmp->next;
// }
	cmd->cmd_arr = ft_convert_to_arr_list(&cmd->lst_args);
	poz = ft_find_buitins(cmd->cmd_arr[0], cmd->sets->func);
// ft_putendl_fd("ft_exec_cmd poz: ", 1);
// ft_putnbr_fd(poz, 1);
// ft_putendl_fd("\n", 1);
printf("ft_exec_cmd poz: %d\n", poz);
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
