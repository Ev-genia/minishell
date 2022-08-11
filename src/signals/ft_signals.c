/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:48:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/11 17:29:45 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_signal_ctrl_c(int sig)
{
	write(1, "\n", 1);
	g_exit_code = 128 + sig;
// write(1, "\n", 1);
// ft_putnbr_fd(g_exit_code, 1);
}

void	ft_signal_quit(int sig)
{
	write(1, "\b\b  \b\b", 6);
	write(1, "^\\Quit: ", 8);
	ft_putnbr_fd(sig, 1);
	write(1, "\n", 1);
	g_exit_code = 128 + sig;
// write(1, "\n", 1);
// ft_putnbr_fd(g_exit_code, 1);
}

void	ft_signal_parent_process(void)
{
	signal(SIGINT, ft_signal_ctrl_c);
	signal(SIGQUIT, ft_signal_quit);
}
