/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:16:45 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:08:07 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_word_count(char const *s, char c)
{
	size_t	word_count;
	int		i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

char	*split_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return ((void *)0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_words(char **result, int i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
}

char	**free_result(char ***result, int i)
{
	free_words(*result, i);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (!s)
		return ((void *)0);
	word_count = find_word_count(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return ((void *)0);
	i = -1;
	while (++i < word_count)
	{
		while (*s && *s == c)
			s++;
		result[i] = split_word(s, c);
		if (!result[i])
			return (free_result(&result, i));
		while (*s && *s != c)
			s++;
	}
	result[i] = (void *)0;
	return (result);
}
