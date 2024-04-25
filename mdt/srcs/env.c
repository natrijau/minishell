/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/25 13:33:51 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
int exit_error(t_data *data, char *str);
int get_env(t_data *data, char **envp)
{
	int i;
	t_env *node;

	i = 0;
	while(envp[i] != NULL)
	{
		add_env_node(data);
		node = ft_lstlast_env(data->env);
		node->var =ft_substr(envp[i], 0, found_equal(envp[i], '='));
		node->value = ft_substr(envp[i], found_equal(envp[i], '='), ft_strlen(envp[i]));
		node->origin = 1;
		i++;
	}
	return (0);
}

// int sort_env()
// {
	
// }

// int add_var_env()
// {
	
// }

int	add_env_node(t_data *data)
{
	t_env	*node;

	if (data->env == NULL)
	{
		data->env = ft_lstnew_env(data->env);
		if (data->env == NULL)
			exit_error(data, "Memory allocation issue");
	}
	else
	{
		node = ft_lstnew_env(data->env);
		if (node == NULL)
			exit_error(data, "Memory allocation issue");
		ft_lstadd_back_env(&(data->env), node);
	}
	return (0);
}
int	found_equal(const char *string, int searchedChar)
{
	int			i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)searchedChar)
			return (i);
		i++;
	}
	return (0);
}

int exit_error(t_data *data, char *str)
{
	(void)data;
	(void)str;
	return (1);
}