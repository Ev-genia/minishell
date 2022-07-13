/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:26:41 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 11:04:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

char	*ft_find_key_env(char *env)
{
	int		i;
	char	*key;

	i = 0;
	while (env[i] != '=')
		++i;
	key = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (env[++i] != '=')
		key[i] = env[i];
	key[i] = '\0';
	return (key);
}

char	*ft_find_value_env(char *env)
{
	int		i;
	char	*val;

	i = 0;
	while (env[i] != '=')
		++i;
	i++;
	val = ft_strdup(&env[i]);
	return (val);
}

t_env	*ft_env_struct(char **ev)
{
	int		i;
	t_env	*env_new;
	t_env	*env_list;
	char	*key;
	char	*value;

	env_list = NULL;
	i = -1;
	while (ev[++i])
	{
		key = ft_find_key_env(ev[i]);
		value = ft_find_value_env(ev[i]);
		env_new = ft_lstnew_env(key, value);
		ft_lstadd_back_env(&env_list, env_new);
		free(key);
		free(value);
	}
	return (env_list);
}

void	ft_env(t_env *env)
{
	t_env	*e;

	e = env;
	while (e)
	{
		printf("%s=%s\n", e->key, e->value);
		e = e->next;
	}
}
