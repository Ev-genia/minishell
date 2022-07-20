/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/20 12:53:34 by mlarra           ###   ########.fr       */
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

// minishell(→_→)$>
	return (0);
}
