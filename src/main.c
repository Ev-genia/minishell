/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/15 14:52:06 by mlarra           ###   ########.fr       */
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
		// ft_add_history(str);
		add_history(str);
	 }
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

int	main(int argc, char **argv, char **env)
{
	t_set	set;
	int		status;
	char	*str;
	
	status = 0; //статус завершения команды при execve  или builtin-команде
	(void)argc;
	(void)argv;
	ft_init_set(&set, env);
	ft_init_func(set.func);
	ft_init_arr(set.choice_func);
	ft_signal_init();

set.lst_cmds = malloc(sizeof(t_cmd));
set.lst_cmds->lst_args = ft_lstnew("cat");
set.lst_cmds->file_read = NULL;
set.lst_cmds->file_write = NULL;
set.lst_cmds->flag_heredoc_read = 0;
set.lst_cmds->flag_heredoc_write = 0;
set.lst_cmds->flag_pipe = 1;
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
// set.lst_cmds->next->flag_pipe = 0;
// set.lst_cmds->next->flag_redir_read = 0;
// set.lst_cmds->next->flag_redir_write = 0;
// set.lst_cmds->next->limiter = NULL;
// set.lst_cmds->next->sets = &set;
// set.lst_cmds->next->next = NULL;

	while (status == 0)
	{
		str = readline("\033[36m(→_→)$\033[0m ");
		add_history(str);
		if (!str)
			exit(0);
		// dup2(set.start_fd_in, 0);
		while (set.lst_cmds)
		{
			ft_command(*(set.lst_cmds));
			set.lst_cmds = set.lst_cmds->next;
		}
		// set.lst_cmds = ft_parse(str, &set);

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
