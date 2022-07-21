/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:25:33 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/21 10:14:06 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

void	ft_lstclear_env(t_env **lst)
{
	t_env	*tmp;
	t_env	*list;

	list = *lst;
	while (list)
	{
		tmp = list->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(list);
		list = tmp;
	}
	*lst = (void *)0;
}
