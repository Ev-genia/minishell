/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:48:26 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/25 15:50:00 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_word(char *str, int *i)
{
	int		j;
	char	*word;

	j = *i;
	while (str[*i] && !is_space(str[*i]) && !ft_strchr("|<>", str[*i]))
		(*i)++;
	//word = malloc(sizeof(char) * (*i - j + 1));
	word = ft_substr(str, j, *i - j);
	if (!word)
		malloc_error_exit("minishell: malloc error for word");
	return (word);
}

char	*ft_word_after_quotes(t_cmd *cmd, char **str, int *i)
{
	int 	j;
	int		count;
	char	*word;

	count = 0;
	j = *i;
	if (*str[*i] == '\'')		
		*str = ft_quote(*str, i, &count);
	else if (*str[*i] == '\"')
		*str = ft_db_quote(*str, i, &count, cmd);
	//word = malloc(sizeof(char) * (count + 1));
	word = ft_substr(*str, j, count);
	if (!word)
		return (NULL);
	return (word);
}