/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/13 17:33:03 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parse(int argc, char **argv)
{
	
}


int	main(int argc, char **argv, char **env)
{
	
	//основной main:
	if (ft_parse(argc, argv))
		return (ft_error());
	/*if (ft_init(argc, argv))
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
	char	*arg_export[6];

	arg_export[0] = "export";
	arg_export[1] = "test1";
	arg_export[2] = "TEST2";
	arg_export[3] = "Test3=";
	arg_export[4] = "tEST4=HI";
	arg_export[5] = NULL;
	enpv = ft_env_struct(env);
	sort_env = ft_sorted_export(enpv);
	ft_export(arg_export, sort_env);
// */
	return (0);
}
