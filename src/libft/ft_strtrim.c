/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                   : +:+ +:+         +:+    */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:13:38 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/21 18:36:52 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start(char const *s1, char const *set)
{
	int	start_ind;

	start_ind = 0;
	while (s1[start_ind] && ft_strchr(set, s1[start_ind]) != NULL)
		start_ind++;
	return (start_ind);
}

int	find_stop(char const *s1, char const *set)
{
	int	stop_ind;

	stop_ind = ft_strlen(s1) - 1;
	while (s1[stop_ind] && stop_ind > 0 && ft_strchr(set, s1[stop_ind]) != NULL)
		stop_ind--;
	return (stop_ind);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_ind;
	int		stop_ind;
	char	*result;
	int		i;

	if (!s1 || !set)
		return ((void *)0);
	start_ind = find_start(s1, set);
	stop_ind = find_stop(s1, set);
	if (start_ind >= stop_ind)
		return (ft_strdup(""));
	result = malloc(sizeof(*s1) * (stop_ind - start_ind + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	while ((start_ind + i) <= stop_ind)
	{
		result[i] = s1[start_ind + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
