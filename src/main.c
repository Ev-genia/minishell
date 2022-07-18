/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/18 16:39:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{

	t_env	*enpv;
	t_env	*export;

	(void)argc;
	enpv = ft_env_struct(env);
	export = ft_sorted_export(enpv);

		// основной main:
	ft_parse(&argv[1], enpv);
	/*if (ft_parse(argv, enpv))
		return (ft_error());
	if (ft_init(argc, argv))
	    return (ft_error());
	ft_shell();
	*/
// /*
//for test unset

	// char	*arg_unset1[2];
	char	*arg_unset2[3];

	(void)argv;
	// arg_unset1[0] = "unset";
	// arg_unset1[1] = NULL;
	// ft_unset(arg_unset1, &enpv, &export);
	arg_unset2[0] = "unset";
	arg_unset2[1] = "__CF_USER_TEXT_ENCODING";
	arg_unset2[2] = NULL;
	ft_env(enpv);
	ft_unset(arg_unset2, &enpv, &export);
ft_putstr_fd("-----------------\n", 1);
	ft_env(enpv);
// */

	return (0);
}
