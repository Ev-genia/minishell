/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/14 23:14:16 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

/*
void	ft_swap(t_env **l)
{
	t_env	*temp;

	temp = (*l)->next;
	(*l)->next = (*l)->next->next;
	temp->next = (*l);
	(*l) = temp;
}
*/

void	ft_swap_content(t_env **l)
{
	void	*temp_key;
	void	*temp_value;
	int		temp_flag;

	temp_key = (*l)->key;
	(*l)->key = (*l)->next->key;
	(*l)->next->key = temp_key;
	temp_value = (*l)->value;
	(*l)->value = (*l)->next->value;
	(*l)->next->value = temp_value;
	temp_flag = (*l)->flag_key;
	(*l)->flag_key = (*l)->next->flag_key;
	(*l)->next->flag_key = temp_flag;
}

int	ft_lstsize_t_env(t_env *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_max_len(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (len1);
	return (len2);
}

t_env	*ft_sorted_export(t_env *list)
{
	t_env	*begin;
	int		len_list;
	int		i;
	int		max_len;

	begin = list;
	len_list = ft_lstsize_t_env(list);
	i = 0;
	while (i < len_list)
	{
		list = begin;
		while (list->next != NULL)
		{
			max_len = ft_max_len(list->key, list->next->key);
			if (ft_strncmp(list->key, list->next->key, max_len) > 0)
				ft_swap_content(&list);
			list = list->next;
		}
		i++;
	}
	return (begin);
}

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	ft_print_export(t_env *export)
{
	t_env	*e;

	e = export;
	while (e)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(e->key, 1);
		if (e->flag_key == 1)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('\"', 1);
			ft_putstr_fd(e->value, 1);
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
		e = e->next;
	}
}

void	ft_export(char **arg, t_env *export)
{
	// int	i;

	// i = 0;
	if (ft_arr_len(arg) == 1)
		ft_print_export(export);
	else
	{
		// while (arg[++i] != NULL)
		// 	ft_add_to_export(&export, arg[i]);
		export = ft_sorted_export(export);
	}
}
