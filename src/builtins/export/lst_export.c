/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:25:33 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/19 14:41:48 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*temp;
// 	t_list	*list;

// 	list = *lst;
// 	while (list)
// 	{
// 		temp = list->next;
// 		if (list->content)
// 			del(list->content);
// 		free(list);
// 		list = temp;
// 	}
// 	*lst = (void *)0;
// }

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
