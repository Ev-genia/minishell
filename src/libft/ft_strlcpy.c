/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/17 13:01:47 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (source[i] && i < (size - 1))
		{
			destination[i] = source[i];
			i++;
		}
		destination[i] = '\0';
	}
	return (ft_strlen(source));
}
