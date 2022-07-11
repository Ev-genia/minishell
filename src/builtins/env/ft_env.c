/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:26:41 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/11 16:41:37 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

void	ft_env(t_env *env)
{
	t_env	*e;

	e = env;
	if (e)
	{
		printf("%s=%s\n", e->name, e->value);
		e = e->next;
	}
}

// int main()
// {
// 	t_env test;

// 	test.name = "test1";
// 	test.value = "TEST1";
// 	test.next = NULL;
// 	ft_env(&test);
// 	return (0);
// }