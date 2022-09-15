/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:20:58 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/14 16:47:50 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

char	**ft_convert_to_arr_env(t_env *list)
{
	char	**arr;
	int		size_lst;
	int		i;
	t_env	*lst;
	char	*tmp1;
	char	*tmp2;

	lst = list;
	size_lst = ft_lstsize_env(lst);
	arr = malloc(sizeof(char *) * (size_lst + 1));
	i = -1;
	while (++i < size_lst)
	{
		tmp1 = ft_strdup(lst->key);
		tmp2 = ft_strjoin(tmp1, "=");
		free(tmp1);
		arr[i] = ft_strjoin(tmp2, lst->value);
		free(tmp2);
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_convert_to_arr_list(t_list *list)
{
	char	**arr;
	int		size_lst;
	int		i;

t_list	*tmp;
tmp = list;
while (tmp)
{
	printf("lst_arg: |%s|\n", (char *)tmp->content);
	tmp = tmp->next;
}

	size_lst = ft_lstsize(list);
	arr = malloc(sizeof(char *) * (size_lst + 1));
	i = 0;

	while (i < size_lst)
	{
		arr[i] = ft_strdup((char *)list->content);
		list = list->next;
		i++;
	}
	arr[i] = NULL;

ft_putendl_fd("arr:", 1);
i = 0;
while (i < size_lst)
{
	ft_putendl_fd(arr[i], 1);
	i++;
}

	return (arr);
}
