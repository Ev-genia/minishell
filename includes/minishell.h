/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:45:26 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/11 16:06:03 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
// # include "libft/libft.h"
# include "../src/libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>

typedef struct s_env //связный список для парсинга переменной окружения
{
	char			*name;
	char			*value;
	struct s_env	*next;
	
}t_env;

#endif