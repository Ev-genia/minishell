/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:17:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/07/14 11:12:36 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_preparse(char **av)
{
	return (0);
}

char	*ft_quote(char *str, int i)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = i;
	while (str[++i])
	{
		if (str[i] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j - 1);
	tmp1 = ft_substr(str, j + 1, i - j);
	tmp2 = ft_strdup(str + j + 1);

	return (NULL);
}


int	ft_parse(char **av, t_env *env_list)
{
	int	i;
	int	j;

	i = 0;

/*TODO: НАПИСАТЬ ПРЕПАРСЕР!!!!!!!!!!!!!!!!!!*/ 
	// if (ft_preparse(av) == 1)
	// 	return (1);

	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '\'')
				ft_quote(av[i], j);
			j++;
		}
		i++;
	}
	return (0);
}

