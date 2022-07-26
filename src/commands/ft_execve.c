/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 11:55:17 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_write(char *s)
{
	int	i;

	write(2, "command not found: ", 19);
	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	write(2, "\n", 1);
}

char	*ft_get_path_from_env(t_env *env, int poz)
{
	int		i;
	t_env	*list;

	list = env;
	i = -1;
	while (++i < poz)
		list = list->next;
	return (list->key);
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
	char	**env_arr;
	char	**cmd_arr;

	path = ft_get_path((char *)cmd.lst_args->content, env);
	if (!path)
	{
		ft_write((char *)cmd.lst_args->content);
		// free(lst?);
		exit(1);
	}
	env_arr = ft_convert_to_arr_env(env);
	cmd_arr = ft_convert_to_arr_list(cmd.lst_args);
	if (execve(path, cmd_arr, env_arr))
	{
		perror(cmd_arr[0]);
		perror(path);
		exit(1);
	}
}
