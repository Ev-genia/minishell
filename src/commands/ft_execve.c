/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 16:39:36 by mlarra           ###   ########.fr       */
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
// int i = -1;
// while (++i < ft_arr_len(tracks))
// {
// 	ft_putstr_fd(tracks[i], 1);
// 	ft_putstr_fd("\n", 1);
// }
	str = ft_check_path(command, tracks);
// ft_putstr_fd("str: \n", 1);
// ft_putstr_fd(str, 1);
// ft_putstr_fd("\n", 1);
	return (str);
}

void	ft_execve(t_cmd cmd, t_env *env)
{
	char	*path;

	path = ft_get_path((char *)cmd.lst_args->content, env);
// ft_putstr_fd("path: \n", 1);
// ft_putstr_fd(path, 1);
// ft_putstr_fd("\n", 1);
	if (!path)
	{
		ft_write((char *)cmd.lst_args->content);
		// free(lst?);
		exit(1);
	}
	if (cmd.sets->env_arr != NULL)
		ft_free_arr(cmd.sets->env_arr);
	cmd.sets->env_arr = ft_convert_to_arr_env(env);
	
// int j = -1;
// while (++j < ft_arr_len(cmd.sets->env_arr))
// {
// 	ft_putstr_fd(cmd.sets->env_arr[j], 1);
// 	ft_putchar_fd('\n', 1);
// }

	if (cmd.cmd_arr != NULL)
		ft_free_arr(cmd.cmd_arr);
	cmd.cmd_arr = ft_convert_to_arr_list(cmd.lst_args);
	
// ft_putstr_fd("------\n", 1);
// int i = -1;
// while (++i < ft_arr_len(cmd.cmd_arr))
// {
// 	// ft_putstr_fd("command\n", 1);
// 	ft_putstr_fd(cmd.cmd_arr[i], 1);
// 	ft_putchar_fd('\n', 1);
// }
	
	if (execve(path, cmd.cmd_arr, cmd.sets->env_arr) == -1)
	{
ft_putstr_fd("command not executable\n", 1);
		perror(cmd.cmd_arr[0]);
		// perror(path);
		// free(path);
		// if (cmd.cmd_arr != NULL)
		// 	ft_free_arr(cmd.cmd_arr);
		// if (cmd.sets->env_arr != NULL)	
		// 	ft_free_arr(cmd.sets->env_arr);
		exit(1);
	}
}
