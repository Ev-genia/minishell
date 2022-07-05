/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:41:18 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/24 15:43:33 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*list;

	list = *lst;
	while (list)
	{
		temp = list->next;
		if (list->content)
			del(list->content);
		free(list);
		list = temp;
	}
	*lst = (void *)0;
}
