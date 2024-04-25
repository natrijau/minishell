/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/25 15:10:13 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
int exit_error(t_data *data, char *str);

// A ajouter : quand on appel la fcontion export -> ajouter une nouvelle variable dans t_env dans l'ordre
void	alpha_order(t_env *env)
{
	t_env *tmp;
	int len;
	char *str_temp;
	
	tmp = env;
	str_temp = NULL;
	len = 0;
	while (tmp->next != NULL)
	{
		if (ft_strlen(tmp->var) >= ft_strlen(tmp->next->var) )
			len = ft_strlen(tmp->var);
		else
			len = ft_strlen(tmp->next->var);
		if (ft_strncmp(tmp->var, tmp->next->var, len) > 0)
		{
			str_temp = ft_strdup(tmp->next->var);
			free(tmp->next->var);
			tmp->next->var = ft_strdup(tmp->var);
			free(tmp->var);
			tmp->var = ft_strdup(str_temp);
			free(str_temp);
			tmp = env;
		}
		else
			tmp = tmp->next;
	}
}

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
		node->value = ft_substr(envp[i], found_equal(envp[i], '=') + 1, ft_strlen(envp[i]));
		node->origin = 1;
		i++;
	}
	alpha_order(data->env);
	return (0);
}

// int sort_env(t_data *data)
// {
// 	t_env *node;

// 	node = data->env;
// 	while(node != NULL);
// 	{
// 		if ()
// 	}
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