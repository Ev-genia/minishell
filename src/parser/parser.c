/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:17:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/09/26 13:11:07 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_arg_to_cmd(char *str, int *i, t_cmd *cmd)
{
	char	*arg_name;
	t_list	*lst;

	lst = NULL;
	if (!(arg_name = ft_word(str, i)))
		return ;

	lst = ft_lstnew(arg_name);
	//free(arg_name);
	ft_lstadd_back(&(cmd->lst_args), lst);
}

t_cmd	*ft_parse(char *str1,  t_set *sets)
{
	int		i;
	char	*str;
	t_cmd	*lst_cmds;
	t_cmd	*cmd;
	int		count;

	i = 0;
	lst_cmds = NULL;
	if (ft_preparse(str1, i) == 1)
		return (NULL);
	str = ft_del_spaces(str1);
	while (str[i] != '\0')
	{
		cmd = ft_cmd_lst_new(sets);
		if (!cmd)
			return (cmd_error_return(lst_cmds));
		while (str[i] && str[i] != '|')
		{
			if (str[i] && str[i] == '<')
				str = ft_redirect_read(cmd, str, &i);
			if (str[i] && str[i] == '>')
				str = ft_redirect_write(cmd, str, &i);
			if (str[i] && is_space(str[i]))
				skip_spaces(str, &i);							
			if (str[i] && !ft_strchr("<>|$\"\'?", str[i]))
				ft_add_arg_to_cmd(str, &i, cmd);
			if (str[i] == '\'')
			{
				str = ft_quote(str, &i, &count);
				continue;
			}
			if (str[i] == '\"')
			{
				str = ft_db_quote(str, &i, &count, cmd);
				continue;
			}
			if (str[i] == '$')
			{
				str = ft_dollar(str, &i, sets->enpv, cmd);
				continue;
			}
			i++;
		}
		ft_cmd_lst_add_back(&lst_cmds, cmd);
		if (str[i] == '|')
		{
			lst_cmds->flag_pipe = 1;
			i++;
		}
	}
	return (lst_cmds);
}
