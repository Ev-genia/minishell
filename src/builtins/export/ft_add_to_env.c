/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:13:16 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/20 12:46:52 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

t_env	*ft_env_new_elem(char *s)
{
	char	*key;
	char	*val;
	t_env	*env_new;

	if (ft_strchr(s, '=') != NULL)
	{
		key = ft_find_env(s, 'k');
		val = ft_find_env(s, 'e');
		env_new = ft_lstnew_env(key, val, 1);
		free(key);
		free(val);
		return (env_new);
	}
	return (NULL);
}

void	ft_add_to_env(t_env **list, char *s)
{
	t_env	*env_new;

	env_new = ft_env_new_elem(s);
	if (env_new != NULL)
		ft_lstadd_back_env(list, env_new);
}
