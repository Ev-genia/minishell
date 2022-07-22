/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:09 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/22 10:18:55 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

void	ft_old_pwd(char *old_pwd, t_env **env, t_env **export)
{
	int		poz;
	char	*pwds;

	poz = ft_find_key_id("OLDPWD", *env);
	if (poz != -1)
	{
		pwds = ft_strjoin("OLDPWD=", old_pwd);
		ft_add_to_export(export, pwds);
		ft_add_to_env(env, pwds);
		free(pwds);
	}
}

void	ft_new_pwd(t_env **env, t_env **export)
{
	char	*pwd;
	int		poz;
	char	*new_pwd;

	pwd = getcwd(NULL, 1024);
	if (!pwd)
	{
		perror("pwd error");
		return ;
	}
	poz = ft_find_key_id("PWD", *env);
	if (poz != -1)
	{
		new_pwd = ft_strjoin("PWD=", pwd);
		ft_add_to_export(export, new_pwd);
		ft_add_to_env(env, new_pwd);
		free(new_pwd);
	}
	free(pwd);
}

int	ft_cd(char **args, t_env **export, t_env **env)
{
	char	*old_pwd;

	(void)env;
	(void)export;
	if (ft_arr_len(args) == 1)
		return (0);
	old_pwd = getcwd(NULL, 1024);
	if (!old_pwd)
	{
		perror("old_pwd error");
		return (1);
	}
	if (chdir(args[1]) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(args[1]);
		return (1);
	}
	ft_old_pwd(old_pwd, env, export);
	ft_new_pwd(env, export);
	free(old_pwd);
	return (0);
}
