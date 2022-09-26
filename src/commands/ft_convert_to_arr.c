/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:20:58 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/23 11:37:43 by mlarra           ###   ########.fr       */
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

char	**ft_convert_to_arr_list(t_list **list)
{
	char	**arr;
	int		size_lst;
	int		i;

t_list	*tmp = *list;
// while (tmp)
// {
// 	printf("tmp->content: %s\n", (char *)tmp->content);
// 	tmp = tmp->next;
// }

	size_lst = ft_lstsize(*list);
// printf("size_lst: %d\n", size_lst);
// size_lst = 2;
	arr = (char **) malloc(sizeof(char *) * (size_lst + 1));
	tmp = *list;
	i = 0;
	while (i < size_lst)
	{
		arr[i] = ft_strdup((char *)tmp->content);
// 		arr[i] = strdup((char *)tmp->content);
printf("ft_convert_to_arr_list arr[%d]: %s\n", i, arr[i]);
		// arr[i] = (char *)malloc(sizeof(char) * (strlen(arr[i]) + 1));
// printf("test2\n");
		// strcpy(arr[i], (char *)tmp->content);
// printf("arr[%d]: %s\n", i, arr[i]);
		tmp = tmp->next;
		i++;
	}
	arr[i] = NULL;
printf("----------\n");
	return (arr);
}
