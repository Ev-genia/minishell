/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:16:58 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 14:55:27 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_count_arg_echo(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

void	ft_echo(char **arg)
{
	int	i;

	i = 0;
	if (ft_count_arg_echo(arg) == 1)
		printf("%s\n", arg[i]);
	else
		printf("%s", arg[++i]);
}
