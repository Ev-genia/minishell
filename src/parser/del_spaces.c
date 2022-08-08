/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:47:20 by wcollen           #+#    #+#             */
/*   Updated: 2022/08/08 14:48:00 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_del_spaces(char *str)
{
	char	*new_str;

	new_str = ft_strtrim(str, " ");
	return (new_str);
}