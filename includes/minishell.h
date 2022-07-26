/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 10:18:16 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
// # include "libft/libft.h"
# include "../src/libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include "../src/get_next_line/get_next_line.h"

typedef struct s_env //связный список для парсинга переменной окружения
{
	char			*key;
	char			*value;
	int				flag_key;
	struct s_env	*next;
}	t_env;

struct s_set;

typedef struct s_cmd
{
	struct s_set	*sets;
	t_list			*lst_args;
	int				flag_pipe;
	int				flag_redir_read;
	int				flag_heredoc_read;
	int				flag_redir_write;
	int				flag_heredoc_write;
	char			*file_read;
	char			*file_write;
	char			*limiter;//стоп-слово для heredoc
	struct s_cmd	*next;//?
}	t_cmd;

typedef struct s_set
{
	t_env	*enpv;
	char	**env_arr;
	t_env	*export;
	t_cmd	*lst_cmds;//list of commands
}	t_set;

int	g_exit_code;

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

typedef int	(*t_arr_f[10])(t_list *lst_args, t_env **export, t_env **env);

//lst_env.c
t_env	*ft_lstnew_env(char *content1, char *content2, int flag);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);

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
int		ft_command(t_cmd cmd, t_func *func, t_arr_f choice_func);

//ft_execve.c
void	ft_execve(char *command, t_env *env);

//ft_herdoc.c
void	ft_herdoc(t_cmd cmd);
void	ft_perror(char *str);

//ft_dup_data.c
void	ft_dup_child_data(t_cmd cmd, int *fd_pipe);//t_cmd cmd);
void	ft_dup_parent_data(int *fd_pipe, t_cmd cmd, pid_t pid);

//ft_init_arr_func.c
void	ft_init_f(t_func *func);
void	ft_init_arr(t_arr_f ft_choice_func);

//=================parser.c========================//
t_cmd	*ft_parse(char *str, t_env *env_list);

#endif
