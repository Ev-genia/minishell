/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/17 15:11:13 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int symb, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		if (*s == (unsigned char)symb)
			return (s);
		s++;
	}
	return (0);
}
