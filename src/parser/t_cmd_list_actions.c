/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_list_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:41:22 by wcollen           #+#    #+#             */
/*   Updated: 2022/07/27 11:01:21 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lst_cmd_new(t_set	*sets)
{
	t_cmd	*new;
	
	struct s_set	*sets;
	t_list			*lst_args;
	char			**cmd_arr;//in start cmd_arr = NULL
	int				flag_pipe;
	int				flag_redir_read;
	int				flag_heredoc_read;
	int				flag_redir_write;
	int				flag_heredoc_write;
	char			*file_read;
	char			*file_write;
	char			*limiter;//стоп-слово для heredoc
	struct s_cmd	*next;

	new = malloc(sizeof(t_cmd));
	if (new)
	{
		new->sets = sets;
		new->lst_args = NULL;
		new->cmd_arr = NULL;
		new->flag_pipe = 0;
		new->flag_redir_read = 0;
		new->flag_heredoc_read = 0;
		new->flag_redir_write = 0;
		new->flag_heredoc_write = 0;
		new->file_read = NULL;
		new->file_write = NULL;
		new->limiter = NULL;
		new->next = NULL;	
	}
	return (new);
}