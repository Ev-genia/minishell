/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/15 14:41:38 by mlarra           ###   ########.fr       */
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

void	ft_no_valid_export(char *str)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
}

void	ft_export(char **arg, t_env *export)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_arr_len(arg) != 1)
	{
		while (arg[++i] != NULL)
		{
			if (j == 0 && (ft_isdigit(arg[i][j]) || !ft_isalpha(arg[i][j])))
				return (ft_no_valid_export(arg[i]));
			if (!ft_isdigit(arg[i][j]) && !ft_isalpha(arg[i][j]))
				return (ft_no_valid_export(arg[i]));
			ft_add_to_export(&export, arg[i]);
		}
		export = ft_sorted_export(export);
	}
	ft_print_export(export);
}
