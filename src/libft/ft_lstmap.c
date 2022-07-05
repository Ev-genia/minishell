/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:02 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/24 19:42:31 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_elem;
	t_list	*new_list_begin;

	new_list_begin = NULL;
	while (lst)
	{
		new_list_elem = ft_lstnew(f(lst->content));
		if (!new_list_elem)
		{
			ft_lstclear(&new_list_begin, del);
			return ((void *)0);
		}
		ft_lstadd_back(&new_list_begin, new_list_elem);
		lst = lst->next;
	}
	return (new_list_begin);
}
