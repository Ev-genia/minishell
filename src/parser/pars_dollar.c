/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:14:32 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/23 14:10:22 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_dollar(char *str, int *i, t_env *env_list, t_cmd *cmd)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	if (str[*i + 1] == '?')
	{
		if (!(tmp = ft_word(str, i)))
			return (NULL);
		ft_lstadd_back(&(cmd->lst_args), ft_lstnew(tmp));
		free(tmp);
		return (str);
	}
	while (str[++*i])
	{
		if (!is_key(str[*i], *i))
			break;
	}
	if (*i == j + 1)
	{
		if (!(tmp = ft_word(str, i)))
			return (NULL);
		ft_lstadd_back(&(cmd->lst_args), ft_lstnew(tmp));
		free(tmp);
		return (str);
	}
	tmp = ft_substr(str, j + 1, *i - j - 1);

	int t = ft_strlen(str + *i);
	char *ttt;
	if (t > 0)
		ttt = ft_strdup(str + *i);;

	while (env_list)
	{
		if (ft_strncmp(tmp, env_list->key, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = ft_substr(str, 0, j);
			tmp1 = strdup(env_list->value);
			ft_lstadd_back(&(cmd->lst_args), ft_lstnew(env_list->value));
			*i = j + ft_strlen(env_list->value);
			tmp2 = ft_strjoin(tmp, tmp1);
			free(tmp);
			free(tmp1);
			//tmp1 = ttt;//ft_strdup(str + *i);
			tmp = ft_strjoin(tmp2, ttt);
			free(ttt);
			free(tmp2);
			return (tmp);
		}
		env_list = env_list->next;
	}
	return (str);
}