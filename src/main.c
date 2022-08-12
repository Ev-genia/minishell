/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/12 16:09:53 by mlarra           ###   ########.fr       */
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
		ft_putstr_fd("\n", fd);
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
	 //rl_clear_history();??????????????????
	 return (str);
}

int	main(int argc, char **argv, char **env)
{
	t_set	set;
	int		status;
	char	*str;
	
	status = 0; //статус завершения команды при execve  или builtin-команде
	(void)argc;
	(void)argv;
	ft_init_set(&set, env);
	ft_init_f(set.func);
	ft_init_arr(set.choice_func);
	while (status == 0)
	{
		ft_signal_parent_process();
		ft_term_caps(&set);//перевод терминала в неканонический режим
		str = ft_readline("\033[36mminishell(→_→)$\033[0m ");
		signal(SIGQUIT, ft_handler);
		tcsetattr(0, TCSANOW, &set.orig_term);//перевод терминала в канонический режим
		if (!str)
			exit(0);
		set.lst_cmds = ft_parse(str, &set);

		// if (!set.lst_cmds)
		// {
		// 	         //сначала функция очистки листов!!!!!!!
		//  	ft_putstr_fd("\nArguments error\n", 2);
		// }
	
// while (set.lst_cmds && status == 0)
// {
// 	status = ft_command(*set.lst_cmds, func, choice_func);
// 	ft_putstr_fd(set.lst_cmds->lst_args->content, 1);
// 	set.lst_cmds = set.lst_cmds->next;
// }	
		// if (ft_parse(argv, set.enpv))
		// 	return (ft_error());
		// status = ft_shell();	

		free(str);
	}
	//ft_wait();

	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);

	// rl_clear_history();

	return (0);
}
