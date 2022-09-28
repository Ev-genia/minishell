/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/09/29 00:17:53 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../src/libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>
// # include <curses.h> ?

int			g_exit_code;

typedef struct s_env
{
	char				*key;
	char				*value;
	int					flag_key;
	struct s_env		*next;
}	t_env;	

// enum e_type
// {
// 	EMPTY,
// 	CMD,
// 	ARG,
// 	TRUNC,
// 	HEREDOC,
// 	APPEND,
// 	INPUT,
// 	PIPE
// };

// typedef struct s_token
// {
// 	char			*str;
// 	enum e_type		type;
// 	struct s_token	*next;
// 	struct s_token	*prev;
// }t_token;

struct		s_set;	

typedef struct s_cmd
{	
	struct s_set		*sets;
	t_list				*lst_args;
	char				**cmd_arr;
	int					flag_pipe;
	int					fd_pipin;
	int					fd_pipout;
	int					pid;
	int					flag_redir_read;
	int					fd_in;
	int					flag_heredoc_read;
	int					flag_redir_write;
	int					fd_out;
	int					flag_heredoc_write;
	char				*file_read;
	char				*file_write;
	char				*limiter;
	struct s_cmd		*next;
	int					charge;
	// int					fds_pipe[2];
	int					flag_prev_pipe;
}	t_cmd;	

enum e_func_name	
{	
	FT_ECHO,
	FT_ENV,
	FT_EXIT,
	FT_EXPORT,
	FT_CD,
	FT_PWD,
	FT_D_Q
};	

typedef struct s_func
{	
	char				*name_func;
	enum e_func_name	type;
}	t_func;	

typedef int	(*t_arr_f[8])(t_list *lst_args, t_env **export, t_env **env);

typedef struct s_set
{	
	t_env			*enpv;
	char			**env_arr;
	t_env			*export;
	t_cmd			*lst_cmds;
	int				start_fd_in;
	int				start_fd_out;
	t_func			func[8];
	t_arr_f			choice_func;
	// int				*fds_pipe[2];
	// pid_t			*pids;
	// struct termios	new_term;
	// struct termios	orig_term;
	int				exit;
}	t_set;

// typedef struct s_term
// {
// 	char	buf[2048];
// 	char	*term_name;
// 	// int		iter;
// 	// char	line[2048];
// }	t_term;

//lst_env.c
t_env	*ft_lstnew_env(char *content1, char *content2, int flag);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
int		ft_lstsize_env(t_env *lst);

//ft_env.c
int		ft_env(t_list *lst_args, t_env **export, t_env **env);
t_env	*ft_env_struct(char **ev);
char	*ft_find_env(char *env, char c);

//ft_pwd.c
int		ft_pwd(t_list *lst_args, t_env **export, t_env **env);

//ft_echo.c
int		ft_echo(t_list *lst_args, t_env **export, t_env **env);

//ft_export.c
int		ft_export(t_list *lst_args, t_env **export, t_env **env);
int		ft_arr_len(char **arr);
void	ft_no_valid_command(char *str, char *name_command, char *message);
int		ft_check_arg_export(char *s);

//ft_sort_export.c
t_env	*ft_sorted_export(t_env *list);
int		ft_max_len(char *s1, char *s2);
t_env	*ft_copy_env(t_env *list);

//ft_add_to_export.c
void	ft_add_to_export(t_env **export, char *s);
int		ft_find_position(t_env *list, char *key);

//lst_export.c
void	ft_lstclear_env(t_env **lst);

//ft_add_to_env.c
void	ft_add_to_env(t_env **list, char *s);

//ft_unset.c
int		ft_unset(t_list *lst_args, t_env **env, t_env **export);
int		ft_find_key_id(char *key, t_env *list);

//ft_cd.c
int		ft_cd(t_list *lst_args, t_env **export, t_env **env);

//ft_exit.c
int		ft_exit(t_list *lst_args, t_env **export, t_env **env);

//ft_dollar_question.c
int		ft_dollar_question(t_list *lst_args, t_env **export, t_env **env);

//ft_command.c
void	ft_command(t_cmd *cmd);
// int		ft_command(t_cmd cmd, int i);
int		ft_find_buitins(char *command, t_func *func);

//ft_execve.c
void	ft_execve(t_cmd cmd, t_env *env);
char	*ft_get_path(char *command, t_env *env);

//ft_exec.c
void	ft_exec_cmd(t_cmd *cmd);
int		ft_exec_bin(t_cmd *cmd);

//ft_execve_utils.c
void	ft_write(char *s);
void	ft_free_arr(char **arr);
void	print_error_exit(char *str);

//ft_herdoc.c
void	ft_herdoc(t_cmd *cmd);
void	ft_perror(char *str);

//ft_dup_data.c
// void	ft_dup_child_data(t_cmd cmd, int *fd_pipe);
// int		ft_dup_parent_data(int *fd_pipe, t_cmd cmd, pid_t pid1);
void	ft_open_outfile(t_cmd *cmd);

//ft_convert_to_arr.c
char	**ft_convert_to_arr_env(t_env *list);
char	**ft_convert_to_arr_list(t_list **list);

//ft_init_arr_func.c
void	ft_init_func(t_func *func);
void	ft_init_arr(t_arr_f ft_choice_func);

//ft_t_cmd_utils.c
int		ft_lstsize_cmd(t_cmd *lst);

//ft_init_set.c
void	ft_init_set(t_set **set, char **env);

// //ft_term_caps.c
// void	ft_term_caps(t_set *set);

//ft_shell.c
void	ft_shell(t_cmd *cmds);

//ft_fds.c
void	ft_close(int fd);
void	ft_reset_std(t_set *set);
void	ft_close_fds(t_cmd *cmd);
void	ft_reset_fds(t_cmd *cmd);

//ft_minipipe.c
void	ft_input(t_cmd *cmd);
int		ft_minipipe(t_cmd *cmd);

//ft_signal_init.c
void	ft_signal_init(void);
void	ft_signal_ctrl_d(int sig);
void	ft_signal_ctrl_c(int sig);
void	ft_signal_handler(int sig);
void	ft_signal_ctrl_c_child(int sig);

// ft_handler.c
void	ft_handler(int status);

//=================parser.c=======================//
t_cmd	*ft_parse(char *str, t_set *sets);
void	skip_spaces(char *str, int *i);

//=================pars_utils.c===================//
char	*ft_del_spaces(char *str);
void	skip_spaces(char *str, int *i);
int		is_key(char c, int i);
void	malloc_error_exit(char *str);
void	*cmd_error_return(t_cmd	*lst_cmds);

//=================lst_cmd_operations.c============//
t_cmd	*ft_cmd_lst_new(t_set	*sets);
void	ft_cmd_lst_add_back(t_cmd	**cmd_lst, t_cmd *new);
void	ft_cmd_lst_clear(t_cmd **cmd_lst);

//================preparser.c=====================//
int	ft_preparse(char *str, int i);

//=================pars_word.c====================//
char	*ft_word(char *str, int *i);
char	*ft_word_after_quotes(t_cmd *cmd, char **str, int *i);

//===============pars_redirect.c==================//
char	*ft_redirect_read(t_cmd *cmd, char *str, int *i);
char	*ft_redirect_write(t_cmd *cmd, char *str, int *i);

//===============pars_quotes.c====================//
char	*ft_db_quote(char *str, int *i, int *count, t_cmd *cmd);
char	*ft_quote(char *str, int *i, int *count);

//===============pars_dollar======================//
char	*ft_dollar(char *str, int *i, t_env *env_list, t_cmd *cmd);

//================pars_strjoin.c==================//
char	*ft_pars_strjoin(char const *s1, char const *s2);
#endif
