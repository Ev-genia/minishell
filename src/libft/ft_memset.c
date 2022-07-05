/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:51:07 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/10 18:35:08 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	int				i;

	dest = b;
	i = 0;
	while (len > 0)
	{
		dest[i] = c;
		i++;
		len--;
	}
	return (dest);
}
