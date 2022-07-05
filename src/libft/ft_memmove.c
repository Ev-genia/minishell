/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/17 12:27:45 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t len)
{
	unsigned char		*to;
	const unsigned char	*from;

	to = destination;
	from = source;
	if (from < to)
	{
		while (len > 0)
		{
			to[len - 1] = from[len - 1];
			len--;
		}
	}
	else if (from > to)
		ft_memcpy(to, from, len);
	return (to);
}
