/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/27 15:39:36 by mlarra           ###   ########.fr       */
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
		add_history(str);
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
	t_set	*set;
	char	*str;
	int		status;

	(void)argc;
	(void)argv;
	set = (t_set *)malloc(sizeof(t_set));
	ft_init_set(&set, env);
	ft_init_func(set->func);
	ft_init_arr(set->choice_func);
	while (1)
	{
		ft_reset_std(set);
		str = ft_readline("\033[36m(→_→)$\033[0m ");
		set->lst_cmds = ft_parse(str, set);
		// free(str);
		while(set->lst_cmds)
		{
			ft_command(set->lst_cmds);
			set->lst_cmds = set->lst_cmds->next;
		}
		while(waitpid(-1, &status, 0) > 0)
			continue;
		g_exit_code = WEXITSTATUS(status);
		ft_cmd_lst_clear(&set->lst_cmds);
	}
	// ft_wait();
	// ft_lstclear_env(&set->enpv);
	// ft_lstclear_env(&set->export);
	return (0);
}
