/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/20 13:31:13 by wcollen          ###   ########.fr       */
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
