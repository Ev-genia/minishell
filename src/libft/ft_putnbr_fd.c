/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:15:54 by wcollen           #+#    #+#             */
/*   Updated: 2021/10/22 18:05:07 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_char(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		put_char(n / 10, fd);
		put_char(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	put_char(n, fd);
}
