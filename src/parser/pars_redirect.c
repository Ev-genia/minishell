/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:55:50 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/26 22:12:16 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_redirect_read(t_cmd *cmd, char *str, int *i)
{	
	(*i)++;
	skip_spaces(str, i);
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		cmd->flag_redir_read = 1;
		if (!(cmd->file_read = ft_word_after_quotes(cmd, &str, i)))
		{
			ft_putendl_fd("minishell: malloc error for read file", 2);
			return (NULL);//Освободить память всю!!!!!
		}	
	}
	else if (str[*i] && str[*i] != '<')
	{
		cmd->flag_redir_read = 1;
		if (!(cmd->file_read = ft_word(str, i)))
			return (NULL);//////Сделат освобождение памяти!!!!!!!!
	}
	else if (str[*i] && str[*i] == '<')
	{
		cmd->flag_heredoc_read = 1;
		(*i)++;
		skip_spaces(str, i);
		if (str[*i] == '\'' || str[*i] == '\"')
		{
			if (!(cmd->limiter = ft_word_after_quotes(cmd, &str, i)))
				return (NULL);////Сделат освобождение памяти!!!!!!!!
		}
		else if (str[*i])
		{
			if (!(cmd->limiter = ft_word(str, i)))
				return (NULL);//Освободить память всю!!!!!
		}
	}
	return (str);
}

char	*ft_redirect_write(t_cmd *cmd, char *str, int *i)
{
	(*i)++;
	skip_spaces(str, i);
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		cmd->flag_redir_write = 1;
		if (!(cmd->file_write = ft_word_after_quotes(cmd, &str, i)))
			return (NULL);
	}
	else if (str[*i])
	{
		if (str[*i] != '>')
			cmd->flag_redir_write = 1;
		else if (str[*i] == '>')
			cmd->flag_heredoc_write = 1;
		if (!(cmd->file_write = ft_word(str, i)))
			return (NULL);
	}
		return (str);
}