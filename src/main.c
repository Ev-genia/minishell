/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/27 16:30:27 by mlarra           ###   ########.fr       */
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
	// int		status;
	// char	*str;
	t_func	func[10];
	t_arr_f	choice_func;

	
	// status = 0; //статус завершения команды при execve  или builtin-команде
	(void)argc;
	(void)argv;
	ft_init_set(&set, env);
	ft_init_f(func);
	ft_init_arr(choice_func);
/*	
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
	//ft_wait();
	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);
	// rl_clear_history();
*/	
// /*
	//for test ft_command with list
	//echo -n pirivet | pwd
	//cat norm > f1
	//<f1 cat > f2
	//<norm grep "Error" | cat > f1
	//cat > f2
	//<< stop cat > f1
	//pwd | << stop cat > f1
	//pwd | cat >> f1
	set.lst_cmds = malloc(sizeof(t_cmd));
	set.lst_cmds->lst_args = ft_lstnew("pwd");
	// set.lst_cmds->lst_args->next = ft_lstnew("Error");
	// set.lst_cmds->lst_args->next->next = ft_lstnew("pirivet");
	set.lst_cmds->file_read = NULL;
	set.lst_cmds->file_write = "f1";
	set.lst_cmds->flag_heredoc_read = 0;
	set.lst_cmds->flag_heredoc_write = 0;
	set.lst_cmds->flag_pipe = 1;
	set.lst_cmds->flag_redir_read = 0;
	set.lst_cmds->flag_redir_write = 0;
	set.lst_cmds->limiter = NULL;
	set.lst_cmds->sets = &set;
	// set.lst_cmds->next = NULL;

	set.lst_cmds->next = malloc(sizeof(t_cmd));
	set.lst_cmds->next->lst_args = ft_lstnew("cat");
	set.lst_cmds->next->file_read = NULL;
	set.lst_cmds->next->file_write = "f1";
	set.lst_cmds->next->flag_heredoc_read = 1;
	set.lst_cmds->next->flag_heredoc_write = 0;
	set.lst_cmds->next->flag_pipe = 0;
	set.lst_cmds->next->flag_redir_read = 0;
	set.lst_cmds->next->flag_redir_write = 1;
	set.lst_cmds->next->limiter = "stop";
	set.lst_cmds->next->sets = &set;
	set.lst_cmds->next->next = NULL;

	while (set.lst_cmds)
	{
		ft_command(*(set.lst_cmds), func, choice_func);
		set.lst_cmds = set.lst_cmds->next;
	}
	// ft_putnbr_fd(status, 1);
	// ft_putchar_fd('\n', 1);
// */

	return (0);
}
