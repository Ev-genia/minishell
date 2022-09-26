/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/23 15:37:40 by mlarra           ###   ########.fr       */
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
	// char	*str;

	(void)argc;
	(void)argv;
	set = (t_set *)malloc(sizeof(t_set));
	ft_init_set(&set, env);
	ft_init_func(set->func);
	ft_init_arr(set->choice_func);
	// while (1)
	// {
	// 	// str = ft_strdup("<d1 cat");
		// str = ft_readline("\033[36m(→_→)$\033[0m ");
	// 	set->lst_cmds = ft_parse(str, set);

	set->lst_cmds = malloc(sizeof(t_cmd));
	set->lst_cmds->lst_args = ft_lstnew("grep");
	set->lst_cmds->lst_args->next = ft_lstnew("src");
	set->lst_cmds->lst_args->next->next = ft_lstnew("norm");
	set->lst_cmds->file_read = NULL;
	set->lst_cmds->file_write = NULL;
	set->lst_cmds->flag_heredoc_read = 0;
	set->lst_cmds->flag_heredoc_write = 0;
	set->lst_cmds->flag_pipe = 1;
	// set->lst_cmds->flag_pipe = 0;
	set->lst_cmds->flag_redir_read = 0;
	set->lst_cmds->flag_redir_write = 0;
	set->lst_cmds->limiter = NULL;
	set->lst_cmds->sets = set;
	// set->lst_cmds->next = NULL;

	set->lst_cmds->next = malloc(sizeof(t_cmd));
	set->lst_cmds->next->lst_args = ft_lstnew("cat");
	set->lst_cmds->next->file_read = NULL;
	set->lst_cmds->next->file_write = "f1";
	set->lst_cmds->next->flag_heredoc_read = 0;
	set->lst_cmds->next->flag_heredoc_write = 0;
	set->lst_cmds->next->flag_pipe = 0;
	set->lst_cmds->next->flag_redir_read = 0;
	set->lst_cmds->next->flag_redir_write = 1;
	set->lst_cmds->next->limiter = NULL;
	set->lst_cmds->next->sets = set;
	set->lst_cmds->next->next = NULL;

/*
t_list	*test = set->lst_cmds->lst_args;
char	**arr_test;
int		j;
int		len;

len = ft_lstsize(test);
arr_test = malloc(sizeof(char *) * (len + 1));
arr_test[len] = NULL;
j = 0;
while (j < len)
{
	arr_test[j] = strdup((char *)test->content);
	test = test->next;
	j++;
}
// arr_test[j] = NULL;
j = 0;
while (j < len)
{
	printf("arr_test[%d]: %s\n", j, arr_test[j]);
	j++;
}
*/

// /*
		while(set->lst_cmds)
		{
			if (set->lst_cmds != NULL)
			{

				ft_shell(set->lst_cmds);
				set->lst_cmds = set->lst_cmds->next;
				// set->enpv = ft_env_struct(env);
			}
		}// */
		ft_cmd_lst_clear(&set->lst_cmds);
		// free(str);
	// }
	// ft_wait();
	// ft_lstclear_env(&set->enpv);
	// ft_lstclear_env(&set->export);
	return (0);
}
