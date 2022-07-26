/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 12:17:21 by wcollen          ###   ########.fr       */
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
	// char	**args_cmd;
	t_func	func[10];
	t_arr_f	choice_func;

	
	status = 0; //статус завершения команды при execve  или builtin-команде
	(void)argc;
	(void)argv;
	set.enpv = ft_env_struct(env);
	set.export = ft_copy_env(set.enpv);
//set.export = ft_sorted_export(set.export);
	ft_init_f(func);
	ft_init_arr(choice_func);
	while (status == 0)
	{
		str = ft_readline("\033[36mminishell(→_→)$\033[0m ");
		set.lst_cmds = ft_parse(str, set.enpv);
		if (!set.lst_cmds)
		{
			         //сначала функция очистки листов!!!!!!!
		 	ft_putstr_fd("Arguments error", 2);
		}
	
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
	// ft_wait();
	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);
	// rl_clear_history();
	return (0);
}
