/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:32:35 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/11 16:17:33 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!pwd)
	{
		perror("pwd error");
		return (1);
	}
	ft_putstr_fd(pwd, 1);
	write(1, "\n", 1);
	free(pwd);
	return (0);
}

// int main()
// {
// 	ft_pwd();
// 	return (0);
// }