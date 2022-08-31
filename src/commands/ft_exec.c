/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:08:08 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/29 14:04:01 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_exec_cmd(t_cmd *cmd)
{
	int	poz;

	if (cmd->charge == 0)
		return ;
	cmd->cmd_arr = ft_convert_to_arr_list(cmd->lst_args);
	poz = ft_find_buitins((char *)cmd->lst_args->content, cmd->sets->func);
	if (cmd->cmd_arr
		&& ft_strncmp(cmd->cmd_arr[0], "exit", ft_strlen("exit")) == 0
		&& cmd->flag_pipe == 0)
		ft_exit(cmd->lst_args, &cmd->sets->export, &cmd->sets->enpv);
	else if (cmd->cmd_arr && poz > -1)
		g_exit_code = cmd->sets->choice_func[cmd->sets->func[poz].type](cmd->lst_args,
				&cmd->sets->enpv, &cmd->sets->export);
	// else if (cmd->cmd_arr)
	// 	g_exit_code = ft_exec_bin(cmd);
	ft_free_arr(cmd->cmd_arr);
	ft_close(cmd->fd_pipin);
	ft_close(cmd->fd_pipout);
	cmd->fd_pipin = -1;
	cmd->fd_pipout = -1;
	cmd->charge = 0;
}
