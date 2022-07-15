/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/14 15:44:50 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

void	ft_swap(t_env **l)
{
	t_env	*temp;

	temp = (*l)->next;
	(*l)->next = (*l)->next->next;
	temp->next = (*l);
	(*l) = temp;
}

void  swap_lst(t_env **elem)
{
  t_env  *tmp;

  if ((*elem) && (*elem)->next)
  {
    tmp = (*elem)->next;
    (*elem)->next = (*elem)->next->next;
    tmp->next = (*elem);
    *elem = tmp;
  }
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

t_env	*ft_sorted_export(t_env **ev)
{
	// t_env	*sorted;
	t_env	*begin;
	int		len_list;
	int		i;
	int		max_len;
	int		flag_head;
// t_env	*temp;

	flag_head = 0;
	begin = *ev;
	len_list = ft_lstsize_t_env(*ev);
	i = 0;
	while (i < len_list)
	{
		*ev = begin;
		flag_head = 0;
		while ((*ev)->next != NULL)
		{
//printf("1 %s, %s\n", (*ev)->key, (*ev)->next->key);
			max_len = ft_max_len((*ev)->key, (*ev)->next->key);
			if (ft_strncmp((*ev)->key, (*ev)->next->key, max_len) > 0)
				ft_swap(ev);
			if (flag_head == 0)
			{
				begin = *ev;
				flag_head = 1;
			}
	
			*ev = (*ev)->next;
//printf("\n");
		}
//printf("---\n");
		i++;
	}
	while(begin != NULL)
	{
		printf("%s\n", begin->key);	
		begin = begin->next;
	}
	// return (sorted);
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
		// ft_putchar_fd('=', 1);
		// ft_putstr_fd(e->value, 1);
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
		export = ft_sorted_export(&export);
	}
}
