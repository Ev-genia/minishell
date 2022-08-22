/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:48:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/19 16:01:14 by mlarra           ###   ########.fr       */
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

// void	ft_signal_parent_process(void)
// {
// 	signal(SIGINT, ft_signal_ctrl_c);
// 	signal(SIGQUIT, ft_signal_quit);
// }

void	ft_signal_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \n", 2);
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signal_init(void)
{
	// signal(SIGINT, ft_signal_handler);
	signal(SIGINT, ft_handler);
	// signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
