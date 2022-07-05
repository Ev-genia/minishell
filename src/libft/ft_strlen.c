/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:51:07 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/10 16:26:58 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

size_t	ft_strlen(const char *symb)
{
	unsigned long	length;

	length = 0;
	while (*symb)
	{
		length++;
		symb++;
	}
	return (length);
}
