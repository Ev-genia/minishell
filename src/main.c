/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/14 12:39:27 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	*test_env;

	(void)argc;
	test_env = ft_env_struct(env);

	//основной main:
	if (ft_parse(argv, test_env))
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
	// char	*arg_export5[6];
	// char	*arg_export1[2];
t_env	*temp;

	(void)argc;
	(void)argv;
	// arg_export5[0] = "export";
	// arg_export5[1] = "test1";
	// arg_export5[2] = "TEST2";
	// arg_export5[3] = "Test3=";
	// arg_export5[4] = "tEST4=HI";
	// arg_export5[5] = NULL;
	enpv = ft_env_struct(env);

// temp = enpv;
// printf("\n");
// while (temp)
// {
// 	printf("%s=%s\n", temp->key, temp->value);
// 	temp = temp->next;
// }
// printf("----\n");

	sort_env = ft_sorted_export(&enpv);

temp = sort_env;
while (temp)
{
	printf("%s=%s\n", temp->key, temp->value);
	temp = temp->next;
}

	// ft_export(arg_export5, sort_env);
	// printf("-----------------\n");
	// arg_export1[0] = "export";
	// arg_export1[1] = NULL;
	// ft_export(arg_export1, sort_env);
// */
	return (0);
}
