/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/26 13:07:36 by wcollen          ###   ########.fr       */
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
//t_list	*tmp;

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
		str = //ft_strdup("cat d1 d2");//("echo \"$USER\"");
		ft_readline("\033[36m(→_→)$\033[0m ");
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
//t_cmd *tmp = set.lst_cmds;
// while(tmp)
// {
// 	while(tmp->lst_args)
// 	{
// 		printf("ARG %s\n", (char *)tmp->lst_args->content);
// 		tmp->lst_args = tmp->lst_args->next;
// 	}
// 	tmp = tmp->next;
// }
 printf("ARG_OLD %s\n", (char *)set.lst_cmds->lst_args->content);

		while(set.lst_cmds)
		{
			if (set.lst_cmds != NULL)
			{
				ft_shell(set.lst_cmds);
				set.lst_cmds = set.lst_cmds->next;
			}
		}
		ft_cmd_lst_clear(&(set.lst_cmds));
		// status = ft_shell();	
		free(str);
	}
	// ft_wait();
	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);
	// rl_clear_history();

	return (0);
}
