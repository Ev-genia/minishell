/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:00:53 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/21 13:24:20 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_cmd_lst_new(t_set	*sets)
{
	t_cmd	*new;

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

t_cmd	*ft_cmd_lst_last(t_cmd *lst)
{
	while (lst)
	{
		if (lst->next == (void *)0)
			return (lst);
		lst = lst->next;
	}
	return ((t_cmd *)0);
}

void	ft_cmd_lst_add_back(t_cmd **cmd_lst, t_cmd *new)
{
	t_cmd	*last_elem;
	
	if (*cmd_lst)
	{
		last_elem = ft_cmd_lst_last(*cmd_lst);
		last_elem->next = new;
	}
	else
	{
		*cmd_lst = new;
	}
}

void	ft_cmd_lst_clear(t_cmd **cmd_lst)
{
	t_cmd	*temp;
	t_cmd	*list;

	list = *cmd_lst;
	while (list)
	{
		temp = list->next;
		if (list->lst_args)
			ft_lstclear(&(list->lst_args), free);
		if (list->cmd_arr)
			ft_free_arr(list->cmd_arr);
		if (list->file_read)
			free(list->file_read);
		if (list->file_write)
			free(list->file_write);
		if (list->limiter)
			free(list->limiter);
		free(list);
		list = temp;
	}
	*cmd_lst = (void *)0;
}
