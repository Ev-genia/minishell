/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 16:49:56 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// minishell(→_→)$ cat abrakadabra > f1 | pwd > f2;
//< norm cat | cat  > test2

void	ft_add_history(char *str)
{
	int	fd;

	fd = open("history.txt", O_WRONLY + O_CREAT + O_APPEND, 0644);
	if (fd != -1)
	{
		ft_putstr_fd(str, fd);
	}
	close(fd);//надо ли каждый раз закрывать?
}

char	*ft_readline(const char *prompt)
{
	 char *str;

	 str = readline(prompt);
	 if (str != NULL && *str != '\0')
	 {
		ft_add_history(str);
	 }
	 return (str);
}

int	main(int argc, char **argv, char **env)
{
	t_set	set;
	int		status;
	char	*str;
	// char	**args_cmd;
	t_func	func[10];
	t_arr_f	choice_func;
	// int		i;
	// int		j;
	// int		len_cmds;
	
	// status = 0; //статус завершения команды при execve  или builtin-команде
	// (void)argc;
	// (void)argv;
	set.enpv = ft_env_struct(env);
	set.export = ft_copy_env(set.enpv);
	set.export = ft_sorted_export(set.export);
	ft_init_f(func);
	ft_init_arr(choice_func);
	// i = -1;
	while (status == 0)
	{
		str = ft_readline("minishell(→_→)$ ");
		// ft_pre_parse(str, set.enpv);
		set.lst_cmds = ft_parse(str, set.enpv);
		// len_cmds = ft_lstsize(set.lst_cmds);
		// j = -1;
		// while (++j < len_cmds && !status)//len_cmds - количество команд(токенов)
		while (set.lst_cmds && status == 0)
		{
			status = ft_command(*set.lst_cmds, func, choice_func);
			set.lst_cmds = set.lst_cmds->next;
		}	
		// if (ft_parse(argv, set.enpv))
		// 	return (ft_error());
		// status = ft_shell();	
		free(str);
	}
	// ft_wait();
	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);
	// rl_clear_history();
	return (0);
}
