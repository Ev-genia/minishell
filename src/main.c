/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:44:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/06/30 15:23:52 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void    ft_shell()
{
    int i;

    i = 0;
    gchgh


}

int main(int argc, char **argv, char **env)
{
    if (ft_parse(argc, argv))
        return (ft_error());
    if (ft_init(argc, argv))
        return (ft_error());
    ft_shell();
}