/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:51:02 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/12 16:40:12 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

t_env	*ft_lstnew_env(char *content1, char *content2)
{
	t_env	*new;

// printf("content1: %s\n", content1);
	new = malloc(sizeof(t_env));
	if (new)
	{
		new->name = content1;
// printf("new->name: %s\n", new->name);
		new->value = content2;
		new->next = NULL;
	}
	return (new);
}

t_env	*ft_lstlast_env(t_env *lst)
{
// printf("1 ft_lstlast_env - lst->name: %s\n", lst->name);
	while (lst)
	{
// printf("2 ft_lstlast_env - lst->name: %s\n", lst->name);
		if (lst->next == (void *)0)
			return (lst);
		lst = lst->next;
	}
	return ((t_env *)0);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last_elem;

printf("1 ft_lstadd_back_env - new->name: %s\n", new->name);
	if (*lst)
	{
		last_elem = ft_lstlast_env(*lst);
// printf("2.1.1 ft_lstadd_back_env - last_elem->name: %s\n", last_elem->name);
		last_elem->next = new;
printf("2.1.2 ft_lstadd_back_env - last_elem->next->name: %s\n", last_elem->next->name);
	}
	else
	{
		*lst = new;
printf("2.2 ft_lstadd_back_env - lst->name: %s\n", (*lst)->name);
	}
}
