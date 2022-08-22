/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_question.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:41:52 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/19 13:30:57 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_dollar_question(t_list *lst_args, t_env **export, t_env **env)
{
	(void)lst_args;
	(void)export;
	(void)env;
	ft_putstr_fd("\033[36m(→_→)$\033[0m: ", 1);
	ft_putnbr_fd(g_exit_code, 1);
	ft_putstr_fd(": command not found\n", 1);
	g_exit_code = 127;
	return(g_exit_code);
}
