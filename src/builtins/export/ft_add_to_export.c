/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:39:03 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/19 16:35:14 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

t_env	*ft_export_new_elem(char *s)
{
	char	*key;
	char	*val;
	t_env	*export_new;

	if (ft_strchr(s, '=') != NULL)
	{
		key = ft_find_env(s, 'k');
		val = ft_find_env(s, 'e');
		export_new = ft_lstnew_env(key, val, 1);
		free(key);
		free(val);
	}
	else
	{
		key = ft_strdup(s);
		val = malloc(sizeof(char));
		val[0] = '\0';
		export_new = ft_lstnew_env(key, val, 0);
		free(key);
	}
	return (export_new);
}

int	ft_find_position(t_env *list, t_env *elem)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_max_len(elem->key, list->key);
	if (ft_strncmp(elem->key, list->key, len1) < 0)
		return (i);
	while (list->next != NULL)
	{
		i++;
		len1 = ft_max_len(elem->key, list->key);
		len2 = ft_max_len(elem->key, list->next->key);
		if (ft_strncmp(elem->key, list->key, len1) > 0
			&& ft_strncmp(elem->key, list->next->key, len2) < 0)
			return (i);
		list = list->next;
	}
	return (i);
}

void	ft_lstadd_middle(t_env **lst, t_env *elem, int i)
{
	t_env	*begin;
	t_env	*tmp;
	int		j;

	begin = *lst;
	j = -1;
	while (++j < i)
		*lst = (*lst)->next;
	tmp = (*lst)->next;
	(*lst)->next = elem;
	elem->next = tmp;
	*lst = begin;
}

void	ft_add_to_export(t_env **list, char *s)
{
	t_env	*export_new;
	int		i;

	export_new = ft_export_new_elem(s);
	i = ft_find_position(*list, export_new);
	ft_lstadd_middle(list, export_new, i);
}
