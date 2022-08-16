/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arr_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:31:32 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/15 13:04:56 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

void	ft_init_func(t_func *func)
{
	func[0].name_func = "echo";
	func[0].type = FT_ECHO;
	func[1].name_func = "env";
	func[1].type = FT_ENV;
	func[2].name_func = "exit";
	func[2].type = FT_EXIT;
	func[3].name_func = "export";
	func[3].type = FT_EXPORT;
	func[4].name_func = "cd";
	func[4].type = FT_CD;
	func[5].name_func = "pwd";
	func[5].type = FT_PWD;
	func[6].name_func = NULL;
}

void	ft_init_arr(t_arr_f ft_choice_func)
{
	ft_choice_func[0] = ft_echo;
	ft_choice_func[1] = ft_env;
	ft_choice_func[2] = ft_exit;
	ft_choice_func[3] = ft_export;
	ft_choice_func[4] = ft_cd;
	ft_choice_func[5] = ft_pwd;
}
