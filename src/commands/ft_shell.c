/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:17:28 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/23 15:37:00 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

// Tools → Options → Text Editor → [язык] → Tabs → Keep tabs
// Edit->Advanced->View White Space

void	ft_shell(t_cmd *cmds)
{
	// int	status;

	ft_command(cmds);
	// waitpid(-1, &status, 0);
	// status = WEXITSTATUS(status);
	ft_reset_std(cmds->sets);
	ft_close_fds(cmds);
	ft_reset_fds(cmds);
}
