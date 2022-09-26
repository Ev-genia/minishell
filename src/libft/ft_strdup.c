/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:49:57 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/21 14:00:34 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	dst = malloc(sizeof(char) * (str_len + 1));
	if (dst == ((void *)0))
		return ((void *)0);
	while (i < str_len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
