/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:55:48 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/22 12:54:27 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_char_count(int num)
{
	size_t	char_count;

	char_count = 0;
	while (num != 0)
	{
		num = num / 10;
		char_count++;
	}
	return (char_count);
}

char	*ft_itoa(int n)
{
	size_t	char_count;
	char	*str;
	int		sign;

	sign = 2 * (n > 0) - 1;
	char_count = get_char_count(n) + (n <= 0);
	str = malloc(sizeof(char) * (char_count + 1));
	if (!str)
		return ((void *)0);
	if (n == 0)
	{	
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[char_count] = '\0';
	while (n != 0)
	{
		str[--char_count] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[--char_count] = '-';
	return (str);
}
