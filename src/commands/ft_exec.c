/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:08:08 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/25 13:34:03 by mlarra           ###   ########.fr       */
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

	cmd->fd_pipin = -1;
	cmd->fd_pipout = -1;
	cmd->charge = 0;
}
