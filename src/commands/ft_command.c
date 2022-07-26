/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:07 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 17:23:23 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

char	*ft_tolower_str(char *s)
{
	int	i;
	int len;
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

int	ft_find_buitins(char *command, t_func *func)
{
	int	i;

	i = 0;
// ft_putstr_fd("command1:\n", 1);
// ft_putstr_fd(command, 1);
// ft_putstr_fd("\n", 1);
	command = ft_tolower_str(command);
// ft_putstr_fd("command2:\n", 1);
// ft_putstr_fd(command, 1);
// ft_putstr_fd("\n", 1);
	while (ft_strncmp(command, func[i].name_func, ft_strlen(command)) != 0)
		i++;
	if (ft_strncmp(command, func[i].name_func, ft_strlen(command)) == 0)
		return (i);
	return (-1);
}

// void	pipex(t_pipe pipe_struct, int num)
// {
// 	pid_t	pid1;
// 	int		fd_pipe[2];

// 	pipe(fd_pipe);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 		ft_first_child(num, fd_pipe, pipe_struct);
// 	else
// 		ft_parent_proc(num, fd_pipe, pid1, pipe_struct);
// }

void	ft_child_process(t_cmd cmd, t_func *func, t_arr_f choice_func, int *fd_pipe)
{
	int		poz;
	int		rez;
// ft_putstr_fd("ft_child_process\n", 1);
	if (cmd.flag_pipe == 1)
		ft_dup_child_data(cmd, fd_pipe);//cmd);
	poz = ft_find_buitins((char *)cmd.lst_args->content, func);
// printf("poz: %d\n", poz);
// ft_putstr_fd("ft_child_process poz: \n", 1);
// ft_putnbr_fd(poz, 1);
// ft_putstr_fd("\n", 1);
	if (poz > -1)
	{
		rez = choice_func[func[poz].type](cmd.lst_args,
			&cmd.sets->enpv, &cmd.sets->export);
		exit(rez);
	}
	else
		{
// ft_putstr_fd("ft_child_process else \n", 1);
// ft_putnbr_fd(poz, 1);
// ft_putstr_fd("\n", 1);
			ft_execve(cmd, cmd.sets->enpv);
			}
}


int	ft_command(t_cmd cmd, t_func *func, t_arr_f choice_func)
{
	pid_t	pid1;
	int		fd_pipe[2];
	// int		rez;
	// int		poz;
	// pid_t	pid2;
	

	// rez = -1;
	if (cmd.flag_pipe == 1)
		pipe(fd_pipe);
	pid1 = fork();
	if (pid1 == 0)
	{
// ft_putstr_fd("ft_command if fork\n", 1);
		// ft_init_set(cmd.sets, );
		// ft_reset_set();
		ft_child_process(cmd, func, choice_func, fd_pipe);
	}
	else 
		ft_dup_parent_data(fd_pipe, cmd, pid1);
	return (0);
}
