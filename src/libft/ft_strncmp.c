/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:51:07 by wcollen           #+#    #+#             */
/*   Updated: 2022/07/28 17:37:57 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	if (num == 0)
		return (0);
	while (*str1 && *str2 && *str1 != '\0' && *str2 != '\0'
		&& *str1 == *str2 && num > 1)
	{
		str1++;
		str2++;
		num--;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
