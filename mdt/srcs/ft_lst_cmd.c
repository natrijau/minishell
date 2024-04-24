/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:31:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/24 15:34:17 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

t_list_cmd	*ft_lstnew_cmd(t_alloc *lst_alloc)
{
	t_list_cmd	*node;

	node = malloc(sizeof(t_list_cmd));
	if (add_alloc((&lst_alloc), node, NULL))
		return (NULL);
	node->cmd = NULL;
	node->path = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_cmd(t_list_cmd **lst, t_list_cmd *new)
{
	t_list_cmd	*beacon;

	if (lst == NULL || new == NULL)
		return ;
	beacon = ft_lstlast_list_cmd(*lst);
	beacon->next = new;
}

t_list_cmd	*ft_lstlast_list_cmd(t_list_cmd *lst)
{
	t_list_cmd	*beacon;

	if (lst == NULL)
		return (NULL);
	beacon = lst;
	while (beacon != NULL)
	{
		if (beacon->next == NULL)
			return (beacon);
		beacon = beacon->next;
	}
	return (beacon);
}

int	ft_lstsize_c(t_list_cmd *lst)
{
	int		i;
	t_list_cmd	*beacon;

	i = 1;
	if (lst == NULL)
		return (0);
	beacon = lst;
	while (beacon->next != NULL)
	{
		beacon = beacon->next;
		i++;
	}
	return (i);
}