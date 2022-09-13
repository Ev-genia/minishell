/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:47:20 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/13 19:16:38 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_del_spaces(char *str)
{
	char	*new_str;

	new_str = ft_strtrim(str, " ");
	return (new_str);
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] && is_space(str[*i]))
		(*i)++;
}

int	is_key(char c, int i)
{
	if (i == 0 && (c == '_' || ft_isalpha(c)))
	 return (1);
	if (i != 0 && (c == '_' || ft_isalnum(c)))
		return (1);
	return (0);

}