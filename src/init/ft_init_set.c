/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:02:51 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/26 14:34:09 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_init_set(t_set *set, char **env)
{
	set->enpv = ft_env_struct(env);
	set->export = ft_copy_env(set->enpv);
	set->export = ft_sorted_export(set->export);
	set->env_arr = NULL;
	set->lst_cmds = NULL;
}
