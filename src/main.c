/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/21 12:15:41 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// minishell(→_→)$ cat abrakadabra > f1 | pwd > f2;

void	ft_add_history(char *str)
{
	int	fd;

	fd = open("some_file.txt", O_WRONLY + O_CREAT + O_APPEND, 0644);
	if (fd != -1)
	{
		ft_putstr_fd(str, fd);
	}
	close(fd);//надо ли каждый раз закрывать?
}

char	*ft_readline(const char *prompt)
{
	 char * str;

	 str = readline(prompt);
	 if (str)
	 {
		ft_add_history(str);
	 }
	 return (str);
}

int	main(int argc, char **argv, char **env)
{
	t_set	set;
	
	// t_env	*enpv;
	// t_env	*export;
	int		status;
	char	*str;
	// char	**args_cmd;

	status = 0; //статус завершения команды при execve  или builtin-команде

	(void)argc;
	(void)argv;
	set.enpv = ft_env_struct(env);
	set.export = ft_copy_env(set.enpv);
	set.export = ft_sorted_export(set.export);

	while (!status)
	{
		str = ft_readline("minishell(→_→)$ ");
		ft_parse(str, set.enpv);
		// args_cmd = ft_parse(str, set.enpv);
		// status = ft_command(args_cmd, &set.enpv, &set.export);
		/*if (ft_parse(argv, enpv))
			return (ft_error());
		if (ft_init(argc, argv))
			return (ft_error());
		status = ft_shell();
		*/
		free(str);
	}

// /*
	//for test command
	t_cmd	command1;

	command1.args_cmd[0] = "cat";
	command1.args_cmd[1] = NULL;
	command1.flag_pipe = 0;
	ft_command(command1, &set.enpv, &set.export);
// */

	ft_lstclear_env(&set.enpv);
	ft_lstclear_env(&set.export);
	return (0);
}
