/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:26:41 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 15:33:46 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

char	*ft_find_env(char *env, char c)
{
	int		i;
	char	*key;
	char	*val;

	i = 0;
	while (env[i] != '=')
		++i;
	if (c == 'k')
	{
		key = malloc(sizeof(char) * (i + 1));
		i = -1;
		while (env[++i] != '=')
			key[i] = env[i];
		key[i] = '\0';
		return (key);
	}
	else
	{
		i++;
		val = ft_strdup(&env[i]);
		return (val);
	}
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
		key = ft_find_env(ev[i], 'k');
		value = ft_find_env(ev[i], 'v');
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
		ft_putstr_fd(e->key, 1);
		ft_putchar_fd('=', 1);
		ft_putstr_fd(e->value, 1);
		ft_putchar_fd('\n', 1);
		e = e->next;
	}
}
