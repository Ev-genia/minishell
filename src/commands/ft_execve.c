/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/29 14:02:48 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

char	*ft_get_path_from_env(t_env *env, int poz)
{
	int		i;
	t_env	*list;

	list = env;
	i = -1;
	while (++i < poz)
		list = list->next;
	return (list->value);
}

char	*ft_check_path(char *command, char **tracks)
{
	int		i;
	char	*tmp;
	char	*path;

	if (command[0] == '/' || (command[0] == '.' && command[1] == '/')
		|| command[0] == '~')
		return (command);
	i = 0;
	while (tracks[i])
	{
		path = ft_strjoin(tracks[i], "/");
		tmp = ft_strjoin(path, command);
		free(path);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *command, t_env *env)
{
	char	*str;
	int		num_str;
	char	**tracks;
	char	*path_env;

	str = NULL;
	num_str = ft_find_key_id("PATH", env);
	if (num_str == -1)
	{
		ft_write(command);
		// free(lst?);
		exit(1);
	}
	path_env = ft_get_path_from_env(env, num_str);
	tracks = ft_split(path_env, ':');
	str = ft_check_path(command, tracks);
	return (str);
}

void	ft_execve(t_cmd cmd, t_env *env)
{
	char	*path;

	path = ft_get_path((char *)cmd.lst_args->content, env);
	if (!path)
	{
		ft_write((char *)cmd.lst_args->content);
		// free(lst?);
		exit(1);
	}
	if (cmd.sets->env_arr != NULL)
		ft_free_arr(cmd.sets->env_arr);
	cmd.sets->env_arr = ft_convert_to_arr_env(env);
	if (cmd.cmd_arr != NULL)
		ft_free_arr(cmd.cmd_arr);
	cmd.cmd_arr = ft_convert_to_arr_list(cmd.lst_args);
	if (execve(path, cmd.cmd_arr, cmd.sets->env_arr) == -1)
	{
// ft_putstr_fd("\nTEST3 ft_execve\n", 2);		
		perror(cmd.cmd_arr[0]);
		free(path);
		if (cmd.cmd_arr != NULL)
			ft_free_arr(cmd.cmd_arr);
		if (cmd.sets->env_arr != NULL)
			ft_free_arr(cmd.sets->env_arr);
		g_exit_code = 1;
		exit(1);
	}
}

// int	ft_magic_exec(t_cmd *cmd)
// {
// 	int	rez;

// 	rez = 0;
// 	cmd->pid = fork();
// 	if (cmd->pid == 0)
// 	{

// 		execve();
// 	}
// 	else
// 		waitpid(cmd->pid, &rez, 0);
	
// 	return (rez);
// }

// int	ft_exec_bin(t_cmd *cmd)
// {
// 	int		rez;
// 	char	**bin;

// 	rez = 127;
// 	while (cmd->sets->enpv && cmd->sets->enpv->value 
// 		&& ft_strncmp(cmd->sets->enpv->value, "PATH=", 5) != 0)
// 		cmd->sets->enpv = cmd->sets->enpv->next;
// 	if (cmd->sets->enpv == NULL || cmd->sets->enpv->next == NULL)
// 		return (ft_magic_exec(cmd));
// 	cmd->cmd_arr = ft_convert_to_arr_env(cmd->lst_args);
// 	bin = ft_split(cmd->sets->enpv->value, ':');
// 	if (!cmd->cmd_arr[0] || !bin[0])
// 		return (1);

// 	return (rez);
// }
