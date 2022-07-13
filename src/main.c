/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 15:37:12 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	/*
	//основной main:
	if (ft_parse(argc, argv))
		return (ft_error());
	if (ft_init(argc, argv))
	    return (ft_error());
	ft_shell();
	*/
/*
	//для тестирования env:
	t_env	*test_env;

	(void)argc;
	(void)argv;
	test_env = ft_env_struct(env);
	ft_env(test_env);
*/
/*
	//для тестирования echo
	char	*test1[3];
	char	*test2[4];

	(void)argc;
	(void)argv;
	(void)env;
	test1[0] = "echo";
	test1[1] = "abracadabra\n";
	test1[2] = NULL;
	test2[0] = "echo";
	test2[1] = "-n";
	test2[2] = "testTESTtest|";
	test2[3] = NULL;
	ft_echo(test2);
	ft_echo(test1);
*/
	return (0);
}
