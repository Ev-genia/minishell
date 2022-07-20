/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/21 00:09:56 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// minishell(→_→)$>

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
	t_env	*enpv;
	t_env	*export;
	int		status;
	char	*str;

	status = 0; //статус завершения команды при execve  или builtin-команде

	(void)argc;
	(void)argv;
	enpv = ft_env_struct(env);
	export = ft_copy_env(enpv);
	export = ft_sorted_export(export);

	while (!status)
	{
		str = ft_readline("minishell(→_→)$ ");
		ft_parse(str, enpv);
		/*if (ft_parse(argv, enpv))
			return (ft_error());
		if (ft_init(argc, argv))
			return (ft_error());
		status = ft_shell();
		*/
		free(str);
	}
	return (0);
}
