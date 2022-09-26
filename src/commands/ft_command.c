/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/23 15:37:04 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

char	*ft_tolower_str(char *s)
{
	int		i;
	int		len;
	char	*str;

	i = -1;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	while (++i < len)
		str[i] = ft_tolower(s[i]);
	str[i] = '\0';
	// free(s);
	return (str);
}

int	ft_arr_func_len(t_func *arr)
{
	int	i;

	i = 0;
	while (arr[i].name_func != NULL)
		i++;
	return (i);
}

int	ft_find_buitins(char *command, t_func *func)
{
	int	i;
	int	len;

	i = 0;
	command = ft_tolower_str(command);
	len = ft_arr_func_len(func);
	while (i < len)
	{
		if (ft_strncmp(command, func[i].name_func, ft_strlen(command)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_command(t_cmd *cmd)
{
	int	pipe;
	int	status;

	pipe = 0;
	if (cmd->flag_redir_write || cmd->flag_heredoc_write)
		ft_open_outfile(cmd);
	if (cmd->flag_redir_read || cmd->flag_heredoc_read)
		ft_input(cmd);
	if (cmd->flag_pipe)
		pipe = ft_minipipe(cmd);
	// if (cmd->flag_pipe && cmd->next && pipe != 1)
	// 	ft_command(cmd->next);
printf("ft_command pipe = %d\n", pipe);
	if (pipe != 1)
		ft_exec_cmd(cmd);
	waitpid(-1, &status, 0);
	status = WEXITSTATUS(status);
}
