/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:24:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/15 16:51:18 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_unset(char **arg, t_env **env, t_env **export)
{
	int	i;

	i = 0;
	if (ft_arr_len(arg) == 1)
		return (0);
	(void)env;
	(void)export;
	while (arg[++i] != NULL)
	{
		if (ft_check_arg_export(arg[i]))
		{
			ft_no_valid_command(arg[i], arg[0]);
			return (1);
		}
		
	}
	return (0);
}
