/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:51:02 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 11:04:01 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

t_env	*ft_lstnew_env(char *content1, char *content2)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->key = ft_strdup(content1);
		new->value = ft_strdup(content2);
		new->next = NULL;
	}
	return (new);
}

t_env	*ft_lstlast_env(t_env *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return ((t_env *)0);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last_elem;

	if (*lst)
	{
		last_elem = ft_lstlast_env(*lst);
		last_elem->next = new;
	}
	else
	{
		*lst = new;
	}
}
