/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:10:13 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/21 12:25:31 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char s)
{
	if (s == ' ' || s == '\t' || s == '\n'
		|| s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	number;

	sign = 1;
	number = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		if (number > 9223372036854775807 && sign == 1)
			return (-1);
		if (number > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return (number * sign);
}
