/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:24:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 15:28:42 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_find_key_id(char *key, t_env *list)
{
	int	len;
	int	len_list_key;
	int	i;

	len = (int)ft_strlen(key);
	i = 0;
	while (list)
	{
		if (ft_strncmp(key, list->key, len) == 0)
		{
			len_list_key = (int)ft_strlen(list->key);
			if (len == len_list_key)
				return (i);
		}
		list = list->next;
		i++;
	}
	return (-1);
}

void	ft_del_elem(t_env **list)
{
	t_env	*tmp;

	tmp = (*list)->next;
	(*list)->next = (*list)->next->next;
	free(tmp->key);
	if (tmp->flag_key == 1)
	{
		free(tmp->value);
		tmp->flag_key = 0;
	}
	free(tmp);
}

void	ft_del_first_elem(t_env **list)
{
	t_env	*tmp;

	tmp = (*list);
	*list = (*list)->next;
	free(tmp->key);
	if (tmp->flag_key == 1)
	{
		free(tmp->value);
		tmp->flag_key = 0;
	}
	free(tmp);
}

void	ft_unset_env_export(char *key, t_env **list)
{
	int		poz;
	t_env	*begin;
	int		i;

	poz = ft_find_key_id(key, *list);
	if (poz == -1)
		return ;
	begin = *list;
	if (poz == 0)
	{
		ft_del_first_elem(list);
		return ;
	}
	i = -1;
	while (++i < poz - 1)
		*list = (*list)->next;
	ft_del_elem(list);
	*list = begin;
}

int	ft_unset(t_list *lst_args, t_env **env, t_env **export)
{
	t_list	*list;

	list = lst_args;
	if (ft_lstsize(list) == 1)
		return (0);
	list = list->next;
	while (list)
	{
		if (ft_check_arg_export((char *)list->content))
		{
			ft_no_valid_command((char *)list->content, "unset",
				"': not a valid identifier\n");
			return (1);
		}
		ft_unset_env_export((char *)list->content, env);
		ft_unset_env_export((char *)list->content, export);
		list = list->next;
	}
	return (0);
}
