/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:38:05 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/13 18:16:13 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_quotes(char *str, int i)
{
	int	quote;
	int	dbl_quote;

	quote = 0;
	dbl_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			quote++;
		if (str[i] == '\"')
			dbl_quote++;
		i++;
	}
	if (quote % 2 != 0 && dbl_quote % 2 != 0)
	{
		ft_putendl_fd("minishell: syntax error with open quotes", 2);
		return (1);
	}
	return (0);
}

int	ft_check_dbl_symbols(char *str, int i)
{
	char	*ptrn;

	while (str[i])
	{
		ptrn = ft_substr(str, i, 2);
		if (str[i] && str[i + 1] && ft_strnstr("||&&", ptrn, 4))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(ptrn, 2);
			ft_putendl_fd("'", 2);
			free(ptrn);
			return(1);
		}
		i++;
	}
	return (0);
}

int	ft_check_read_redir(char *str, int i)
{
	if (ft_strncmp(str, "<<<<<", 5) == 0)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<<<'", 2);
		return(1);
	}
	if (ft_strncmp(str, "<<<<", 4) == 0)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
		return(1);
	}
	i++;
	if ((str[i] == '>' && !str[i + 1]) || !str[i] || ft_strncmp(str, "<<<", 3) == 0)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `newline'", 2);
		return(1);
	}
	return (0);
}

int	ft_check_write_redir(char *str, int i)
{
	if (ft_strncmp(str, ">>>>", 4) == 0)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>>'", 2);
		return(1);
	}	
	if ((ft_strncmp(str, ">>>", 3) == 0 ))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `>'", 2);
		return(1);
	}
	if (!str[i] || ((ft_strncmp(str, ">>", 2) == 0)))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `newline'", 2);
		return(1);
	}
	i++;
	if ((str[i] == '<' && !str[i + 1]))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `<'", 2);
		return(1);
	}
	return (0);
}

int	ft_preparse(char *str, int i)
{
	if (ft_check_dbl_symbols(str, 0))
		return (1);
	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return(1);
	}
	if (ft_quotes(str, 0))
		return (1);
	while (str[i])
	{		
		if (str[i] == '<')
		{
			if (ft_check_read_redir(str, i))
				return (1);
		}
		if (str[i] == '>')
		{
			if (ft_check_write_redir(str, i))
				return (1);
		}
		i++;
	}
	return (0);
}