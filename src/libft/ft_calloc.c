/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:09:58 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/20 19:22:19 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*str;

	str = malloc(num * size);
	if (str == (void *)0)
		return ((void *)0);
	ft_memset(str, 0, num * size);
	return (str);
}
