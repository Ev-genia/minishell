/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_caps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:46:57 by mlarra            #+#    #+#             */
/*   Updated: 2022/08/12 11:46:26 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../includes/minishell.h"

/*
Первая функция для перевода в неканонический режим:
void set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(0,&stored_settings);

	new_settings = stored_settings;

		// Отключение канонического режима и вывода на экран 
		// и установка буфера ввода размером в 1 байт 
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_lflag &= (~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0,TCSANOW,&new_settings);
	return;
}
*/

/*
Вторая функция для возвращения в первоначальное состояние:
void reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
}
*/

void	ft_term_caps(t_set *set)
{
	t_term			tc;

	tcgetattr(0, &set->orig_term);
	set->new_term = set->orig_term;
	tc.term_name = getenv("TERM");
// ft_putstr_fd("tc.term_name: " , 1);
// ft_putstr_fd(tc.term_name, 1);
// ft_putstr_fd("\n" , 1);
	set->new_term.c_lflag &= ~(ECHO);
	set->new_term.c_lflag &= ~(ICANON);
	// set->new_term.c_lflag &= ~(ISIG);
	set->new_term.c_cc[VMIN] = 1;
	set->new_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &set->new_term);
}
