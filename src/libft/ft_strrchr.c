/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:51:07 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/18 19:51:53 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symb)
{
	int	length;

	length = ft_strlen(str);
	while (length >= 0)
	{
		if (str[length] == (char)symb)
			return ((char *)&str[length]);
		length--;
	}
	return ((void *)0);
}
