/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:17:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/07/26 17:27:09 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_preparse(char *str)
{
	int	quote;
	int	dbl_quote;

	quote = 0;
	dbl_quote = 0;
	while (*str)
	{
		if (*str == '\'')
			quote++;
		if (*str == '\"')
			dbl_quote++;
		str++;
	}
	if (str - 1 == '|')
		return (1);
	if (quote % 2 == 0 && dbl_quote % 2 == 0)
		return (0);
	return (1);
}

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
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	while (str[++*i])
	{
		if (!is_key(str[*i], *i))
			break;
	}
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	while (env_list)
	{
		if (ft_strncmp(tmp, env_list->key, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = ft_substr(str, 0, j);
			tmp1 = strdup(env_list->value);
			tmp2 = ft_strdup(str + *i + 1);
			free(tmp);
			tmp = ft_strjoin(tmp, tmp1);
			free(tmp);
			tmp = ft_strjoin(tmp, tmp2);
			free(tmp1);
			free(tmp2);
			return (tmp);
		}
		env_list = env_list->next;
	}
	//free(str); //ВЫДЕЛИТЬ ПАМЯТЬ ПОД СТРОКУ С АРГУМЕНТАМИ И ДЕЛАТЬ FREE
	return (str);
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

char	*ft_db_quote(char *str, int *i, t_env *env_list)
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
		if (str[*i] == '$')
			ft_dollar(str, i, env_list);
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
	int		i;
	// t_cmd	*lst_cmds;

	i = 0;
	if (ft_preparse(str) == 1)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'')
			str = ft_quote(str, &i);
		if (str[i] == '\\')
			str = ft_b_slash(str, &i);
		if (str[i] == '\"')
			str = ft_db_quote(str, &i, env_list);
		if (str[i] == '$')
			str = ft_dollar(str, &i, env_list);
		i++;
	}
		printf("%s\n", str);
	return (NULL);
}

