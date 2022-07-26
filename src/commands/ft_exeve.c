/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exeve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 09:34:18 by mlarra           ###   ########.fr       */
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

char	**ft_convert_to_arr(t_env *list)
{
	char	**arr;
	int		size_lst;
	int		i;

	size_lst = ft_lstlast_env(list);
	arr = malloc(sizeof(char *) * (size_lst + 1));
	i = -1;
	while (++i < size_lst)
		arr[i] = malloc(sizeof(char) * ft_strlen(arr[i]));
	arr[++i] = NULL;
	return (arr);
}

void	ft_execve(char *command, t_env *env)
{
	char	*path;
	char	**env_arr;

	path = ft_get_path(command, env);
	if (!path)
	{
		ft_write(command);
		// free(lst?);
		exit(1);
	}
	env_arr = ft_convert_to_arr(env);
	if (execve(path, command, env_arr))
	{
		perror(command);
		perror(path);
		exit(1);
	}
}
