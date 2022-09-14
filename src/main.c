/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/14 12:34:54 by mlarra           ###   ########.fr       */
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
	// {
	// 	// ft_add_history(str);
		add_history(str);
	// }
	// if (!str)
	// 	exit(0);
	// add_history(str);
	//rl_clear_history();??????????????????
	return (str);
}

void	ft_wait()
{
	int	status;
	int	i;

	i = 0;
	while (waitpid(-1, &status, 0))
		i++;
}

// ctrl-C -> "\n" -> parser -> signal(SIGINT, SIGIGN) -> signal(SIGINT, SIG_DFL)

int	main(int argc, char **argv, char **env)
{
	t_set	set;
	char	*str;
t_list	*tmp;

	(void)argc;
	(void)argv;
	ft_init_set(&set, env);// g_exit_code = 0;
	ft_init_func(set.func);
	ft_init_arr(set.choice_func);
	// signal(SIGTSTP, SIG_DFL);
	// ft_signal_init();




	// while (g_exit_code == 0)
	while (1)
	{
		// signal(SIGINT, ft_signal_ctrl_c);
		str = ft_readline("\033[36m(→_→)$\033[0m ");
		// str = ft_strdup("ls -a | cat");
		set.lst_cmds = ft_parse(str, &set);

		// signal(SIGTSTP, SIG_DFL);
		// dup2(set.start_fd_in, 0);
		// signal(SIGQUIT, SIG_IGN);


// str = NULL;
		// add_history(str);
		// if (!str)
		// 	exit(0);
		// dup2(set.start_fd_in, 0);
		// signal(SIGINT, SIG_IGN);
		// while (set.lst_cmds)

		while(set.lst_cmds)
		{
			if (set.lst_cmds != NULL)
			{
tmp = set.lst_cmds->lst_args;
while (tmp)
{
	printf("command_main: |%s|\n", (char *)tmp->content);
	tmp = tmp->next;
}
				ft_shell(set.lst_cmds);
				set.lst_cmds = set.lst_cmds->next;
			}
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
