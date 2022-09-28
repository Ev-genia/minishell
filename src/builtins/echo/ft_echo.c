/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:16:58 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/29 00:56:03 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_echo(t_list *lst_args, t_env **export, t_env **env)
{
	int		enter;
	t_list	*list;

	(void)export;
	(void)env;
	list = lst_args;
	enter = 1;
	list = list->next;
	if (list && ft_strncmp((char *)list->content, "-n", 2) == 0)
	{
		enter = 0;
		list = list->next;
	}
	while (list)
	{
		ft_putstr_fd((char *)list->content, 1);
		if (list->next != NULL)
			ft_putchar_fd(' ', 1);
		else if (enter == 1)
			ft_putchar_fd('\n', 1);
		list = list->next;
	}
	return (0);
}
