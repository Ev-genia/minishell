/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/24 14:36:43 by wcollen          ###   ########.fr       */
=======
/*   Updated: 2022/08/23 17:10:50 by mlarra           ###   ########.fr       */
>>>>>>> acdd0fd90f30bf2e63a1425559abbc8c4f99e16c
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
	int		i;
	
	(void)argc;
	(void)argv;
	ft_init_set(&set, env);// g_exit_code = 0;
	ft_init_func(set.func);
	ft_init_arr(set.choice_func);
	signal(SIGTSTP, SIG_DFL);
	// ft_signal_init();


set.lst_cmds = malloc(sizeof(t_cmd));
set.lst_cmds->lst_args = ft_lstnew("cat");
set.lst_cmds->lst_args->next = ft_lstnew("f1");
set.lst_cmds->file_read = NULL;
set.lst_cmds->file_write = NULL;
set.lst_cmds->flag_heredoc_read = 0;
set.lst_cmds->flag_heredoc_write = 0;
set.lst_cmds->flag_pipe = 0;
set.lst_cmds->flag_redir_read = 0;
set.lst_cmds->flag_redir_write = 0;
set.lst_cmds->limiter = NULL;
set.lst_cmds->sets = &set;
set.lst_cmds->next = NULL;

// set.lst_cmds->next = malloc(sizeof(t_cmd));
// set.lst_cmds->next->lst_args = ft_lstnew("ls");
// set.lst_cmds->next->file_read = NULL;
// set.lst_cmds->next->file_write = NULL;
// set.lst_cmds->next->flag_heredoc_read = 0;
// set.lst_cmds->next->flag_heredoc_write = 0;
// set.lst_cmds->next->flag_pipe = 1;
// set.lst_cmds->next->flag_redir_read = 0;
// set.lst_cmds->next->flag_redir_write = 0;
// set.lst_cmds->next->limiter = NULL;
// set.lst_cmds->next->sets = &set;
// // set.lst_cmds->next->next = NULL;

// set.lst_cmds->next->next = malloc(sizeof(t_cmd));
// set.lst_cmds->next->next->lst_args = ft_lstnew("$?");
// set.lst_cmds->next->next->file_read = NULL;
// set.lst_cmds->next->next->file_write = NULL;
// set.lst_cmds->next->next->flag_heredoc_read = 0;
// set.lst_cmds->next->next->flag_heredoc_write = 0;
// set.lst_cmds->next->next->flag_pipe = 0;
// set.lst_cmds->next->next->flag_redir_read = 0;
// set.lst_cmds->next->next->flag_redir_write = 0;
// set.lst_cmds->next->next->limiter = NULL;
// set.lst_cmds->next->next->sets = &set;
// set.lst_cmds->next->next->next = NULL;

	// while (g_exit_code == 0)
	while (1)
	{
		signal(SIGINT, ft_signal_ctrl_c);
<<<<<<< HEAD
		str = "cat \"d12\" | ls";//ft_readline("\033[36m(→_→)$\033[0m ");
		set.lst_cmds = ft_parse(str, &set);

		while(set.lst_cmds)
		{
			while(set.lst_cmds->lst_args)
			{
				printf("%s\n", (char *)set.lst_cmds->lst_args->content);
				set.lst_cmds->lst_args = set.lst_cmds->lst_args->next;
			}
			set.lst_cmds = set.lst_cmds->next;
		}


=======
		signal(SIGTSTP, SIG_DFL);
		dup2(set.start_fd_in, 0);
		// signal(SIGQUIT, SIG_IGN);
		str = ft_readline("\033[36m(→_→)$\033[0m ");
>>>>>>> acdd0fd90f30bf2e63a1425559abbc8c4f99e16c
// str = NULL;
		// add_history(str);
		// if (!str)
		// 	exit(0);
		// dup2(set.start_fd_in, 0);
		// signal(SIGINT, SIG_IGN);
		i = 0;
		while (set.lst_cmds)
		{
			g_exit_code = ft_command(*(set.lst_cmds));
			// g_exit_code = ft_command(*(set.lst_cmds), i);
// ft_putstr_fd("\n", 1);
// ft_putstr_fd(set.lst_cmds->lst_args->content, 1);
// ft_putstr_fd("\n", 1);
			set.lst_cmds = set.lst_cmds->next;
			i++;
		}

		// 

		// if (!set.lst_cmds)
		// {
		// 	         //сначала функция очистки листов!!!!!!!
		//  	ft_putstr_fd("\nArguments error\n", 2);
		// }
		
		// if (ft_parse(argv, set.enpv))
		// 	return (ft_error());
		// status = ft_shell();	

		free(str);
	}
	ft_wait();

	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);

	// rl_clear_history();

	return (0);
}
