/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 17:11:47 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

t_env	*ft_sorted_export(t_env *ev)
{
	t_env	*sorted;

	return (sorted);
}

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	ft_export(char **arg, t_env *export)
{
	int	i;

	i = 0;
	if (ft_arr_len(arg) == 1)
		ft_print_export(export);
	else
	{
		while (arg[++i] != NULL)
			ft_add_to_export(&export, arg[i]);
		export = ft_sorted_export(export);
	}
}
