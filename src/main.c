/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/19 14:56:21 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{

	t_env	*enpv;
	t_env	*export;

	(void)argc;
	enpv = ft_env_struct(env);
	export = ft_copy_env(enpv);
	export = ft_sorted_export(export);

		// основной main:
	ft_parse(&argv[1], enpv);
	/*if (ft_parse(argv, enpv))
		return (ft_error());
	if (ft_init(argc, argv))
	    return (ft_error());
	ft_shell();
	*/

// /*
// 	для тестирования export
	// t_env	*enpv;
	// t_env	*sort_env;
	char	*arg_export1[2];
	char	*arg_export3[3];
	char	*arg_export5[10];

	// (void)argc;
	(void)argv;
	// enpv = ft_env_struct(env);
	// export = ft_sorted_export(enpv);
	ft_env(enpv);
	arg_export1[0] = "export";
	arg_export1[1] = NULL;
	ft_putstr_fd("1-----------------\n", 1);
	ft_export(arg_export1, &export, &enpv);
	ft_putstr_fd("2-----------------\n", 1);
	ft_env(enpv);
	ft_putstr_fd("3-----------------\n", 1);
	arg_export3[0] = "export";
	arg_export3[1] = "___piper";
	arg_export3[2] = NULL;
	ft_export(arg_export3, &export, &enpv);
	ft_putstr_fd("4-----------------\n", 1);	
	ft_env(enpv);
	ft_putstr_fd("5-----------------\n", 1);	
	arg_export5[0] = "export";
	arg_export5[1] = "test1\0";
	arg_export5[2] = "TEST2\0";
	arg_export5[3] = "Test3=\0";
	arg_export5[4] = "tEST4=HI\0";
	arg_export5[5] = "Test5=   \0";
	arg_export5[6] = "te*rm\0";
	arg_export5[7] = NULL;
	ft_export(arg_export5, &export, &enpv);
	ft_putstr_fd("6-----------------\n", 1);
	ft_env(enpv);
	ft_putstr_fd("7-----------------\n", 1);
// */

/*
//for test cd
	char	*arg_cd1[3];
	// char	*arg_cd2[3];

	arg_cd1[0] = "cd";
	arg_cd1[1] = "/Users/";
	arg_cd1[2] = NULL;
	// arg_cd2[0] = "cd";
	// arg_cd2[1] = "/abracadabra";
	// arg_cd2[2] = NULL;
	ft_pwd();
	ft_putstr_fd("-----------------\n", 1);
	ft_cd(arg_cd1, &enpv, &export);
	ft_pwd();
	// ft_cd(arg_cd2, &enpv, &export);
*/
// minishell(→_→)$>
	return (0);
}
