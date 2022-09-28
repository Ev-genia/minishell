/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/28 16:10:41 by mlarra           ###   ########.fr       */
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

void	sigquit(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_exit_code = 130;
}

static void	ft_signal_quit(int sig)
{
	write(1, "\b\b  \b\b", 6);
	write(1, "^\\Quit: ", 8);
	ft_putnbr_fd(sig, 1);
	write(1, "\n", 1);
	g_exit_code = 131;
}

void	init_signal_child(void)
{
	signal(SIGQUIT, ft_signal_quit);
	signal(SIGINT, sigquit);
}

void	exe_pipe_util(int *fd, t_cmd *cmd, char *path,  t_env *env)
{
	int	poz;

	init_signal_child();
	cmd->sets->env_arr = ft_convert_to_arr_env(env);
	cmd->cmd_arr = ft_convert_to_arr_list(&cmd->lst_args);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	poz = ft_find_buitins(cmd->cmd_arr[0], cmd->sets->func);
	if (cmd->cmd_arr && poz > -1)
	{
		g_exit_code = cmd->sets->choice_func[cmd->sets->func[poz].type](cmd->lst_args,
				&cmd->sets->enpv, &cmd->sets->export);
		exit(g_exit_code);
	}
	if (!path)
		print_error_exit(cmd->cmd_arr[0]);
	if (execve(path, cmd->cmd_arr, cmd->sets->env_arr) == -1)
		perror("Bash: ");
	exit(1);
}

void	exe_pipe(t_cmd *cmd)
{
	char	*path;
	int		fd[2];
	int		pid;

	path = ft_get_path((char *)cmd->lst_args->content, cmd->sets->enpv);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		exe_pipe_util(fd, cmd, path, cmd->sets->enpv);
	if (!path)
		g_exit_code = 1;
	free(path);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	get_data(t_cmd *cmd)
{
	cmd->fd_in = open(cmd->file_read, O_RDONLY, 0700);
	dup2(cmd->fd_in, STDIN_FILENO);
	close(cmd->fd_in);
}

void	start_process(t_cmd *cmd)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd->cmd_arr[0], cmd->cmd_arr, cmd->sets->env_arr) == -1)
			perror("Bash: ");
		exit(1);
	}
}

void	check_next_command(t_cmd *cmd)
{
	t_cmd	*temp;
	int		fd[2];

	temp = cmd;
	dup2(cmd->sets->start_fd_out, STDOUT_FILENO);
	if (temp->next)
	{
		pipe(fd);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
}

void	exe(t_cmd *cmd)
{
	char	*path;
	int		pid;
	int		poz;

	cmd->sets->env_arr = ft_convert_to_arr_env(cmd->sets->enpv);
	cmd->cmd_arr = ft_convert_to_arr_list(&cmd->lst_args);
	poz =  ft_find_buitins(cmd->cmd_arr[0], cmd->sets->func);
	if (!ft_strncmp("./", (char *)cmd->lst_args->content, 2) || !ft_strncmp("/", (char *)cmd->lst_args->content, 1))
		start_process(cmd);
	else if (cmd->cmd_arr && poz > -1)
		g_exit_code = cmd->sets->choice_func[cmd->sets->func[poz].type](cmd->lst_args,
				&cmd->sets->enpv, &cmd->sets->export);
	else
	{
		path = ft_get_path((char *)cmd->lst_args->content, cmd->sets->enpv);
		pid = fork();
		if (pid == 0)
		{
			init_signal_child();
			if (!path)
				print_error_exit(cmd->cmd_arr[0]);
			if (execve(path, cmd->cmd_arr, cmd->sets->env_arr) == -1)
				perror("Bash: ");
			exit(1);
		}
		free(path);
	}
	dup2(cmd->sets->start_fd_in, STDIN_FILENO);
	check_next_command(cmd);
}

void	ft_execve_util(t_cmd *command)
{
	if (command->flag_pipe == 1)
		exe_pipe(command);
	else if (command->flag_redir_read || command->flag_heredoc_read)
	{
		if (command->flag_redir_read)
			get_data(command);
		else
			ft_herdoc(command);
	}
	else if (command->flag_heredoc_write || command->flag_redir_write)
		ft_open_outfile(command);
	else
		exe(command);
}

void	sigint_func(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	init_signal_h(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_func);
}

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
		init_signal_h();
		ft_reset_std(set);
		str = ft_readline("\033[36m(→_→)$\033[0m ");
		set->lst_cmds = ft_parse(str, set);
		// free(str);
		while(set->lst_cmds)
		{
			// ft_command(set->lst_cmds);
			ft_execve_util(set->lst_cmds);
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
