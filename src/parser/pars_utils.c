/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:47:20 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/21 13:32:15 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_del_spaces(char *str)
{
	char	*new_str;

	new_str = ft_strtrim(str, " ");
	free(str);
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

void	malloc_error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	*cmd_error_return(t_cmd	*lst_cmds)
{
	ft_putendl_fd("minishell: list of commands malloc error", 2);
	if (lst_cmds)
		ft_cmd_lst_clear(&lst_cmds);
	return (NULL);
}