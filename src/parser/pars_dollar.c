/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:14:32 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/29 00:42:42 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_find_dollar_question(char *str, int *i, t_cmd *cmd)
{
	char	*res;

	if (!(res = ft_word(str, i)))
		return ;
	ft_lstadd_back(&(cmd->lst_args), ft_lstnew(res));
}

char	*ft_write_base(char *str, int j, char *env_val)
{
	char *tmp1;
	char *tmp2;

	tmp1 = ft_substr(str, 0, j);
	tmp2 = strdup(env_val);		
	tmp1 = ft_pars_strjoin(tmp1, tmp2);
	return (tmp1);
}

char	*ft_write_tail(char *str, int i, char *base)
{
	char	*tail;

	tail = ft_strdup(str + i);
	tail = ft_pars_strjoin(base, tail);
	return (tail);
}
char	*ft_dollar(char *str, int *i, t_env *env_list, t_cmd *cmd)
{
	int		j;
	char	*tmp;
	int		flag;

	j = *i;
	flag = 0;
	if (str[*i + 1] == '?')
	{
		ft_find_dollar_question(str, i, cmd);
		return (str);
	}
	while (str[++*i] && !is_space(str[*i]))
	{
		if (!is_key(str[*i], *i))
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)//не найдена такая переменная
	{
		if (!ft_word(str, i))
			return (NULL);
		ft_lstadd_back(&(cmd->lst_args), ft_lstnew(""));
		return (str);
	}
	tmp = ft_substr(str, j + 1, *i - j - 1);
	while (env_list)
	{
		if (ft_strncmp(tmp, env_list->key, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = ft_write_base(str, j, env_list->value);
			if (ft_strlen(str + *i) > 0)
				tmp = ft_write_tail(str, *i, tmp);
			ft_lstadd_back(&(cmd->lst_args), ft_lstnew(env_list->value));
			*i = j + ft_strlen(env_list->value);
			return (tmp);
		}
		env_list = env_list->next;
	}
	ft_lstadd_back(&(cmd->lst_args), ft_lstnew(""));
	return (str);
}