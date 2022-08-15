/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/15 14:52:37 by mlarra           ###   ########.fr       */
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

struct		s_set;	

typedef struct s_cmd
{	
	struct s_set		*sets;
	t_list				*lst_args;
	char				**cmd_arr;
	int					flag_pipe;
	int					flag_redir_read;
	int					flag_heredoc_read;
	int					flag_redir_write;
	int					flag_heredoc_write;
	char				*file_read;
	char				*file_write;
	char				*limiter;
	struct s_cmd		*next;
}	t_cmd;	

enum e_func_name	
{	
	FT_ECHO,	
	FT_ENV,	
	FT_EXIT,	
	FT_EXPORT,	
	FT_CD,	
	FT_PWD	
};	

typedef struct s_func
{	
	char				*name_func;
	enum e_func_name	type;
}	t_func;	

typedef int	(*t_arr_f[7])(t_list *lst_args, t_env **export, t_env **env);

typedef struct s_set
{	
	t_env			*enpv;
	char			**env_arr;
	t_env			*export;
	t_cmd			*lst_cmds;
	int				start_fd_in;
	t_func			func[7];
	t_arr_f			choice_func;
	// struct termios	new_term;
	// struct termios	orig_term;
}	t_set;

typedef struct s_term
{
	char	buf[2048];
	char	*term_name;
	// int		iter;
	// char	line[2048];
}	t_term;

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

//ft_command.c
int		ft_command(t_cmd cmd);
int		ft_find_buitins(char *command, t_func *func);

//ft_execve.c
void	ft_execve(t_cmd cmd, t_env *env);

//ft_herdoc.c
void	ft_herdoc(t_cmd cmd);
void	ft_perror(char *str);

//ft_dup_data.c
void	ft_dup_child_data(t_cmd cmd, int *fd_pipe);
void	ft_dup_parent_data(int *fd_pipe, t_cmd cmd, pid_t pid1);

//ft_convert_to_arr.c
char	**ft_convert_to_arr_env(t_env *list);
char	**ft_convert_to_arr_list(t_list *list);

//ft_init_arr_func.c
void	ft_init_func(t_func *func);
void	ft_init_arr(t_arr_f ft_choice_func);

//ft_execve_utils.c
void	ft_write(char *s);
void	ft_free_arr(char **arr);

//ft_t_cmd_utils.c
int		ft_lstsize_cmd(t_cmd *lst);

//ft_init_set.c
void	ft_init_set(t_set *set, char **env);

//ft_term_caps.c
void	ft_term_caps(t_set *set);

//ft_signal_init.c
void	ft_signal_init(void);
void	ft_signal_quit(int sig);
void	ft_signal_ctrl_c(int sig);
void	ft_signal_handler(int sig);

// ft_handler.c
void	ft_handler(int status);

//=================parser.c========================//
t_cmd	*ft_parse(char *str, t_set *sets);

//=================del_spaces.c====================//
char	*ft_del_spaces(char *str);

//=================lst_cmd_operations.c============//
t_cmd	*ft_cmd_lst_new(t_set	*sets);
#endif
