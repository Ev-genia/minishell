/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/15 15:09:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	/*
	t_env	*test_env;

	(void)argc;
	test_env = ft_env_struct(env);

	// основной main:
	if (ft_parse(argv, test_env))
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
// /*
// 	для тестирования export
	t_env	*enpv;
	t_env	*sort_env;
	// char	*arg_export5[10];
	// char	*arg_export1[2];
	char	*arg_export3[3];

	(void)argc;
	(void)argv;
	enpv = ft_env_struct(env);
	sort_env = ft_sorted_export(enpv);
	// arg_export1[0] = "export";
	// arg_export1[1] = NULL;
	// ft_export(arg_export1, sort_env);
	// printf("-----------------\n");
	// arg_export5[0] = "export";
	// arg_export5[1] = "test1";
	// arg_export5[2] = "TEST2";
	// arg_export5[3] = "Test3=";
	// arg_export5[4] = "tEST4=HI";
	// arg_export5[5] = "Test5=   ";
	// arg_export5[6] = "te*rm";
	// arg_export5[7] = NULL;
	// ft_export(arg_export5, sort_env);
	arg_export3[0] = "export";
	arg_export3[1] = "___piper";
	arg_export3[2] = NULL;
	ft_export(arg_export3, sort_env);
// */
	return (0);
}
