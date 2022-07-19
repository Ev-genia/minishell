/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:11:39 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/19 15:25:02 by mlarra           ###   ########.fr       */
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

void	ft_no_valid_command(char *str, char *name_command)
{
	ft_putstr_fd(name_command, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("`: not a valid identifier\n", 2);
}

int	ft_check_arg_export(char *s)
{
	int	i;
	int	len;

	i = -1;
	len = (int)ft_strlen(s);
	while (++i < len && s[i] != '=')
	{
		if (i == 0 && s[i] != '_' && (ft_isdigit(s[i]) || !ft_isalpha(s[i])))
			return (1);
		// if (s[i] == '=')
		// 	return (0);
		if (!ft_isdigit(s[i]) && !ft_isalpha(s[i]) && s[i] != '_')
			return (1);
		
	}
	return (0);
}

void	ft_export(char **arg, t_env **export, t_env **env)
{
	int	i;

	
	if (ft_arr_len(arg) != 1)
	{
		i = 0;
		while (arg[++i] != NULL)
		{
			if (ft_check_arg_export(arg[i]))
			{
// printf("arg[%d]: %s\n", i, arg[i]);
				ft_no_valid_command(arg[i], arg[0]);
				return ;
			}
			ft_add_to_export(export, arg[i], env);
			// if (ft_strchr(arg[i], '=') != NULL)
			// 	ft_add_to_env(&env, arg[i]);
		}
		*export = ft_sorted_export(*export);
	}
	ft_print_export(*export);
	// return (export);
}
