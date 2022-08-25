/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:17:58 by wcollen           #+#    #+#             */
/*   Updated: 2022/08/25 23:19:49 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_spaces(char *str, int *i)
{
	while (str[*i] && is_space(str[*i]))
		(*i)++;
}

int	ft_preparse(char *str)
{
	int	quote;
	int	dbl_quote;
	int	i;

	i = 0;
	quote = 0;
	dbl_quote = 0;
	if (str[i] == '|')//не может быть пайпа в начале (чего еще не может быть в начале строки??)
		return (1);
	while (str[i])
	{
		if (str[i] == '\'')
			quote++;
		if (str[i] == '\"')
			dbl_quote++;
		if (str[i] == '<')
		{
			i++;
			skip_spaces(str, &i);
			if (str[i] && (str[i] == '>' || str[i] == '|'))
				return(1);
		}
		if (str[i] == '>')
		{
			i++;
			skip_spaces(str, &i);
			if (str[i] && (str[i] == '<' || str[i] == '|'))
				return(1);
		}
		i++;
	}
	if (str[i - 1] == '|')
		return (1);	
	if (quote % 2 != 0 && dbl_quote % 2 != 0)
		return (1);
	return (0);
}

int	is_key(char c, int i)
{
	if (i == 0 && (c == '_' || ft_isalpha(c)))
	 return (1);
	if (i != 0 && (c == '_' || ft_isalnum(c)))
		return (1);
	return (0);

}

char	*ft_word(char *str, int *i)
{
	int		j;
	char	*word;

	j = *i;
	while (str[*i] && !is_space(str[*i]))
		(*i)++;
	word = malloc(sizeof(char) * (*i - j + 1));
	if (!word)
		return (NULL);////Сделат освобождение памяти!!!!!!!!
	word = ft_substr(str, j, *i - j);
	return (word);
}


char	*ft_dollar(char *str, int *i, t_env *env_list, t_cmd *cmd)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	if (str[*i + 1] == '?')
	{
		if (!(tmp = ft_word(str, i)))
				return (NULL);
		ft_lstadd_back(&(cmd->lst_args), ft_lstnew(tmp));
		free(tmp);
		return (str);
	}
	while (str[++*i])
	{
		if (!is_key(str[*i], *i))
			break;
	}
	if (*i == j + 1)
	{

		if (!(tmp = ft_word(str, i)))
				return (NULL);
		ft_lstadd_back(&(cmd->lst_args), ft_lstnew(tmp));
		free(tmp);
		return (str);
	}
	tmp = ft_substr(str, j + 1, *i - j - 1);
	while (env_list)
	{
		if (ft_strncmp(tmp, env_list->key, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = ft_substr(str, 0, j);
			tmp1 = strdup(env_list->value);
			ft_lstadd_back(&(cmd->lst_args), ft_lstnew(env_list->value));
			*i = j + ft_strlen(env_list->value);
			tmp2 = ft_strjoin(tmp, tmp1);
			free(tmp);
			free(tmp1);
			tmp1 = ft_strdup(str + *i);
			tmp = ft_strjoin(tmp2, tmp1);
		 	

			free(tmp1);
			free(tmp2);
			return (tmp);
		}
		env_list = env_list->next;
	}
	//free(str); //ВЫДЕЛИТЬ ПАМЯТЬ ПОД СТРОКУ С АРГУМЕНТАМИ И ДЕЛАТЬ FREE
	return (str);
}

char	*ft_b_slash(char *str, int *i, t_cmd *cmd)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp2 = NULL;

	j = *i;
	tmp = ft_substr(str, 0, j);
	//printf("tmp=%s\n", tmp2);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
	//free(str); //ВЫДЕЛИТЬ ПАМЯТЬ ПОД СТРОКУ С АРГУМЕНТАМИ И ДЕЛАТЬ FREE
	(*i)++;
	free(tmp2);
	ft_lstadd_back(&(cmd->lst_args), ft_lstnew(tmp));
	return (tmp);
}

char	*ft_db_quote(char *str, int *i, int *count, t_cmd *cmd)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;

	j = *i;
	while (str[++*i])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$'))
			str = ft_b_slash(str, i, cmd);
		if (str[*i] == '$')
			str = ft_dollar(str, i, cmd->sets->enpv, cmd);
		if (str[*i] == '\"')
			break ;

	}
	tmp = ft_substr(str, 0, j);
	*count = *i - j - 1;
	tmp1 = ft_substr(str, j + 1, *count);
	tmp2 = ft_strjoin(tmp, tmp1);
	free(tmp); 
	free(tmp1);
	
	tmp1 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp2, tmp1);
	//free(str);
	free(tmp1);
	free(tmp2);
	*i = j - 1 ;//i на позиции до первой  кавычки
	return (tmp);
}

char	*ft_quote(char *str, int *i, int *count)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;
	int		flag;

	flag = 0;
	j = *i;
	while (str[++*i])
	{
		if (str[*i] == '\'')
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 1)
	{
		tmp = ft_substr(str, 0, j);
		*count = *i - j - 1;//сколько символов будет в кавычках
		tmp1 = ft_substr(str, j + 1, *count);
		tmp2 = ft_strdup(str + *i + 1);
		tmp = ft_strjoin(tmp, tmp1);
		tmp = ft_strjoin(tmp, tmp2);
		//free(str);
		free(tmp1);
		free(tmp2);
		*i = j - 1;
		return (tmp);
	}
	return (str);
}

char	*ft_word_after_quotes(t_cmd *cmd, char **str, int *i)
{
	int 	j;
	int		count;
	char	*word;

	count = 0;
	j = *i; //j на позиции следующей на редиректом после всех пробелов
	if (*str[*i] == '\'')		
		*str = ft_quote(*str, i, &count);
	else if (*str[*i] == '\"')
		*str = ft_db_quote(*str, i, &count, cmd);
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);//Сделат освобождение памяти!!!!!!!!
	word = ft_substr(*str, j, count);
	
	return (word);
}



char	*ft_redirect_read(t_cmd *cmd, char *str, int *i)
{	
	(*i)++;
	skip_spaces(str, i);
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		cmd->flag_redir_read = 1;
		if (!(cmd->file_read = ft_word_after_quotes(cmd, &str, i)))
			return (NULL);//Освободить память всю!!!!!
	}
	else if (str[*i] && str[*i] != '<')
	{
		cmd->flag_redir_read = 1;
		if (!(cmd->file_read = ft_word(str, i)))
			return (NULL);//////Сделат освобождение памяти!!!!!!!!
	}
	else if (str[*i] && str[*i] == '<')
	{
		cmd->flag_heredoc_read = 1;
		(*i)++;
		skip_spaces(str, i);
		if (str[*i] == '\'' || str[*i] == '\"')
		{
			if (!(cmd->limiter = ft_word_after_quotes(cmd, &str, i)))
				return (NULL);////Сделат освобождение памяти!!!!!!!!
		}
		else if (str[*i]) //(str[*i] == '_' || ft_isalnum(str[*i]))
		{
			if (!(cmd->limiter = ft_word(str, i)))
				return (NULL);//Освободить память всю!!!!!
		}
	}
	return (str);
}

char	*ft_redirect_write(t_cmd *cmd, char *str, int *i)
{
	(*i)++;
	skip_spaces(str, i);
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		cmd->flag_redir_write = 1;
		if (!(cmd->file_write = ft_word_after_quotes(cmd, &str, i)))
			return (NULL);//Освободить память всю!!!!!
	}
	else if (str[*i])
	{
		if (str[*i] != '>')
			cmd->flag_redir_write = 1;
		else if (str[*i] == '>')
			cmd->flag_heredoc_write = 1;
		if (!(cmd->file_write = ft_word(str, i)))
			return (NULL);
	}
ft_putstr_fd("file write name: |", 1);
ft_putstr_fd(cmd->file_write, 1);
ft_putstr_fd("|\n", 1);
		return (str);
}

t_cmd	*ft_parse(char *str1,  t_set *sets)
{
	int		i;
	char	*str;
	t_cmd	*lst_cmds;
	t_cmd	*cmd;
	char	*arg_name;
	t_list	*lst;
	int		count;

	i = 0;
	lst_cmds = NULL;
	if (ft_preparse(str1) == 1)
		return (NULL);
	str = ft_del_spaces(str1);
	//free(str1); //почему-то ошибка маллока при освобождении строки

	while (str[i] != '\0')
	{
		cmd = ft_cmd_lst_new(sets);
			if (!cmd)
				return (NULL);
		while (str[i] && str[i] != '|')
		{
			if (str[i] && str[i] == '<')
				str = ft_redirect_read(cmd, str, &i);
			if (str[i] && str[i] == '>')
				str = ft_redirect_write(cmd, str, &i);
			if (str[i] && is_space(str[i]))
				skip_spaces(str, &i);
//КАК ОТЛИЧИТЬ ФАЙЛ ОТ ФЛАГОВ КОМАНДЫ???после команды должен быть файл или флаги команды							
			if (str[i] && !ft_strchr("<>|$\"\'?", str[i]))
			{
				if (!(arg_name = ft_word(str, &i)))
					return (NULL);
				lst = NULL;
				lst = ft_lstnew(arg_name);
				free(arg_name);
				ft_lstadd_back(&(cmd->lst_args), lst);
			}
			if (str[i] == '\'')
			{
				str = ft_quote(str, &i, &count);
				continue;
			}		
			// if (str[i] == '\\')
			// 	str = ft_b_slash(str, &i, cmd);
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

