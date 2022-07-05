/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/20 18:56:51 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t size)
{
	size_t	i;
	size_t	length_dst;
	size_t	length_src;
	size_t	result;
	size_t	j;

	result = 0;
	j = 0;
	length_dst = ft_strlen(destination);
	i = length_dst;
	length_src = ft_strlen(source);
	if (size > length_dst)
		result = length_src + length_dst;
	else
		return (length_src + size);
	while (source[j] && i < (size - 1))
	{
		destination[length_dst] = source[j];
		i++;
		j++;
		length_dst++;
	}
	destination[length_dst] = '\0';
	return (result);
}
