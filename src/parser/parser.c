/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:17:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/08/09 14:55:43 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*skip_spaces(char **str)
{
	int	i;

	i = 0;
	while (*str[i] && is_space(*str[i]))
		i++;
	return (&(*str[i]));
}


int	ft_preparse(char *str)
{
	int	quote;
	int	dbl_quote;

	quote = 0;
	dbl_quote = 0;
	if (*str == '|')//не может быть пайпа в начале (чего еще не может быть в начале строки??)
		return (1);
	while (*str)
	{
		if (*str == '\'')
			quote++;
		if (*str == '\"')
			dbl_quote++;
		if (*str == '<')
		{
			str++;
			skip_spaces(&str);
			if (*str && (*str == '>' || *str == '|'))
				return(1);
		}
		if (*str == '>')
		{
			str++;
			skip_spaces(&str);
			if (*str && (*str == '>' || *str == '|'))
				return(1);
		}
		str++;
	}
	if (*(str - 1) == '|')
		return (1);	
	if (quote % 2 != 0 && dbl_quote % 2 != 0)
		return (1);
	return (0);
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


t_cmd	*ft_parse(char *str1,  t_set *sets)
{
	int		i;
	char	*str;
	// t_cmd	*lst_cmds;


	i = 0;
	// lst_cmds = ft_cmd_lst_new(sets);
	if (ft_preparse(str1) == 1)
		return (NULL);
	str = ft_del_spaces(str1);
	//free(str1); //почему-то ошибка маллока при освобождении строки

	while (str[i] && str[i] != '|')
	{
		// сделать операцию добавить в конец листа
		// if (str[i] == '<')
		// {
		// 	if (str[++i] != '<')
			

		// }
		i++;
	}



	i = 0;
	while (str[i])
	{
		if (str[i])
		if (str[i] == '\'')
			str = ft_quote(str, &i);
		if (str[i] == '\\')
			str = ft_b_slash(str, &i);
		if (str[i] == '\"')
			str = ft_db_quote(str, &i, sets->enpv);
		if (str[i] == '$')
			str = ft_dollar(str, &i, sets->enpv);
		i++;
	}
		printf("%s\n", str);
	return (NULL);
}

