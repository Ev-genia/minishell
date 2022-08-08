/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:00:53 by wcollen           #+#    #+#             */
/*   Updated: 2022/08/08 14:41:14 by wcollen          ###   ########.fr       */
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

void	ft_cmd_lst_add_back(t_cmd	**cmd_lst, t_cmd *new)
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