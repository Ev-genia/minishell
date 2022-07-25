/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:17:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/07/25 14:49:14 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	ft_preparse(char **av)
// {
// 	return (0);
// }

int	is_key(char c, int i)
{
	if (i == 0 && (c == '_' || ft_isalpha(c)))
	 return (1);
	if (i != 0 && (c == '_' || ft_isalnum(c)))
		return (1);
	return (0);

}

char	*ft_dollar(char *str, int *i, t_env *env_list)
{
	int		j;
	char	*tmp = NULL;
(void)env_list;
	j = *i;
	while (str[++*i])
	{
		if (!is_key(str[*i], *i))
			break;
	}
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	//printf("KEY tmp$=%s\n", tmp);
	
	
	//free(str); //ВЫДЕЛИТЬ ПАМЯТЬ ПОД СТРОКУ С АРГУМЕНТАМИ И ДЕЛАТЬ FREE
	return (tmp);
}

char	*ft_b_slash(char *str, int *i)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp2 = NULL;

	j = *i;
	tmp = ft_substr(str, 0, j);
	//printf("tmp=%s\n", tmp2);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
	//free(str); //ВЫДЕЛИТЬ ПАМЯТЬ ПОД СТРОКУ С АРГУМЕНТАМИ И ДЕЛАТЬ FREE
	(*i)++;
	free(tmp2);
	return (tmp);
}

char	*ft_db_quote(char *str, int *i)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;

	j = *i;
	while (str[++*i])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$'))
			str = ft_b_slash(str, i);
		if (str[*i] == '\"')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	//free(str);
	free(tmp1);
	free(tmp2);
	return (tmp);
}

char	*ft_quote(char *str, int *i)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;

	j = *i;
	while (str[++*i])
	{
		if (str[*i] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	//free(str);
	free(tmp1);
	free(tmp2);
	return (tmp);
}


t_cmd	*ft_parse(char *str, t_env *env_list)
{
	int	i;

	i = 0;
/*TODO: НАПИСАТЬ ПРЕПАРСЕР!!!!!!!!!!!!!!!!!!*/ 
	// if (ft_preparse(av) == 1)
	// 	return (1);

	while (str[i])
	{
		if (str[i] == '\'')
			str = ft_quote(str, &i);
		if (str[i] == '\\')
			str = ft_b_slash(str, &i);
		if (str[i] == '\"')
			str = ft_db_quote(str, &i);
		if (str[i] == '$')
			str = ft_dollar(str, &i, env_list);
		i++;
	}
		printf("%s\n", str);
	return (NULL);
}

