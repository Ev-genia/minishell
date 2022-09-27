/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:16:32 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/27 16:41:56 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_write(char *s)
{
	int	i;

	write(2, "command not found: ", 19);
	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	write(2, "\n", 1);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	print_error_exit(char *str)
{
	write(2, "Bash: ", 6);
	write(2, str, ft_strlen(str));
	write (2, ": ", 2);
	write(2, "command not found\n", 18);
	exit (127);
}
