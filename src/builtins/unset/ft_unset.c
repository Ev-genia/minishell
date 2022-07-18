/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:24:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/18 11:52:47 by mlarra           ###   ########.fr       */
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

// void	del(void *cont)
// {
// 	char	*str;

// 	str = cont;

// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!lst || !del || !lst->content)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }

void	ft_del_elem(t_env **list)
{
	t_env	*tmp;

	if ((*list)->next != NULL)
		tmp = (*list)->next;
	else
		tmp = NULL;
	free((*list)->key);
	if ((*list)->flag_key == 1)
		free((*list)->value);
	*list = tmp;
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
	i = -1;
	while (++i < poz)
		*list = (*list)->next;
	ft_del_elem(list);
	*list = begin;
}

void	ft_unset(char **arg, t_env **env, t_env **export)
{
	int	i;
	

	i = 0;
	if (ft_arr_len(arg) == 1)
		return ;
	(void)export;
	while (arg[++i] != NULL)
	{
		if (ft_check_arg_export(arg[i]))
		{
			ft_no_valid_command(arg[i], arg[0]);
			return ;
		}
		ft_unset_env_export(arg[i], env);
		// ft_unset_export(arg[i], export);
	}
}
