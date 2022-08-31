/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2022/08/29 14:54:05 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *pattern, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(pattern) == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < count)
	{
		j = 0;
		while (pattern[j] != '\0' && str[i + j] == pattern[j]
			&& (i + j) < count)
		{
			if (j == (ft_strlen(pattern) - 1))
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return ((void *)(0));
}
