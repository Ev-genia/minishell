/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:09:07 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/29 00:55:36 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_db_quote(char *str, int *i, int *count, t_cmd *cmd)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	while (str[++*i])
	{
		if (str[*i] == '$')
			str = ft_dollar(str, i, cmd->sets->enpv, cmd);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	*count = *i - j - 1;
	tmp1 = ft_substr(str, j + 1, *count);
	tmp2 = ft_strjoin(tmp, tmp1);
	*i = ft_strlen(tmp2);
	free(tmp); 
	free(tmp1);
	tmp1 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp2, tmp1);
	free(str);
	free(tmp1);
	free(tmp2);
	return (tmp);
}

char	*ft_quote(char *str, int *i, int *count)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;
	int		flag;

	flag = 0;
	j = *i;
	while (str[++*i])
	{
		if (str[*i] == '\'')
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
	{
		tmp = ft_substr(str, 0, j);
		*count = *i - j - 1;//сколько символов будет в кавычках
		tmp1 = ft_substr(str, j + 1, *count);
		tmp2 = ft_strdup(str + *i + 1);
		tmp = ft_strjoin(tmp, tmp1);
		tmp = ft_strjoin(tmp, tmp2);
		//free(str);
		free(tmp1);
		free(tmp2);
		*i = j - 1; // на позицию до 1-й кавычки
		return (tmp);
	}
	return (str);
}