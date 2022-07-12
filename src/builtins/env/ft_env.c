/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:26:41 by mlarra            #+#    #+#             */
/*   Updated: 2022/07/12 15:51:12 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <minishell.h>
#include "../../../includes/minishell.h"

char	*ft_find_key_env(char *env)
{
	int		i;
	char 	*key;

	i = 0;
	while (env[i] != '=')
		++i;
	key = malloc(sizeof(char) * (i + 1));
	ft_strlcpy(key, env, i + 1);
	return (key);
}

char	*ft_find_value_env(char *env)
{
	int		i;
	char 	*val;

	i = 0;
	while (env[i] != '=')
		++i;
	i++;
	val = ft_strdup(&env[i]);
	return (val);
}

t_env *ft_env_struct(char **ev)
{
	int		i;
	t_env	*env_new;
	t_env	*env_list;
	// t_env	*begin;
	char	*key;
	char	*value;

t_env	*temp1;

	// begin = env_new;
	env_list = NULL;
	i = -1;
	while (ev[++i])
	{
		key = ft_find_key_env(ev[i]);
// printf("key: %s\n", key);
		value = ft_find_value_env(ev[i]);
// printf("value: %s\n", value);
		env_new = ft_lstnew_env(key, value);
// printf("env_new->key: %s\n", env_new->name);
		ft_lstadd_back_env(&env_list, env_new);

temp1 = env_list;
printf("\n");
while (temp1)
{
	printf("temp->name: %s\n", temp1->name);
	temp1 = temp1->next;
}
printf("\n");


		free(key);
		free(value);
	}

t_env	*temp;

// temp = begin;
temp = env_list;
printf("\n");
while (temp)
{
	printf("temp->name: %s\n", temp->name);
	temp = temp->next;
}
printf("\n");
	return (env_list);
	// return (begin);
}

void	ft_env(t_env *env)
{
	t_env	*e;

	e = env;
	if (e)
	{
		printf("%s=%s\n", e->name, e->value);
		e = e->next;
	}
}

int main(int ac, char **av, char **enpv)
{
// 	t_env test;

// 	test.name = "test1";
// 	test.value = "TEST1";
// 	test.next = NULL;
// 	ft_env(&test);

	t_env	*test_env;

	(void)ac;
	(void)av;
	test_env = ft_env_struct(enpv);
	ft_env(test_env);
	return (0);
}