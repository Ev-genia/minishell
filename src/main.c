/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/15 16:48:09 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{

	t_env	*enpv;
	t_env	*sort_env;
	t_env	*export;

	(void)argc;
	enpv = ft_env_struct(env);
	sort_env = ft_sorted_export(enpv);

	/*	// основной main:
	if (ft_parse(argv, test_env))
		return (ft_error());
	if (ft_init(argc, argv))
	    return (ft_error());
	ft_shell();
	*/
// /*
//for test unset

	char	*arg_unset1[2];
	char	*arg_export1[2];
	// char	*arg_unset2[3];
	
	// (void)argc;
	(void)argv;
	// enpv = ft_env_struct(env);
	// sort_env = ft_sorted_export(enpv);
	arg_export1[0] = "export";
	arg_export1[1] = NULL;
	export = ft_export(arg_export1, sort_env);
	arg_unset1[0] = "unset";
	arg_unset1[1] = NULL;
	ft_unset(arg_unset1, &enpv, &export);
	// arg_unset2[0] = "unset";
	// arg_unset2[1] = "USER";
	// arg_unset2[2] = NULL;
	// ft_unset(arg_unset2, &enpv, &export);
// */

	return (0);
}
