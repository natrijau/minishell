/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:13:53 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/25 14:15:20 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_env_debug(t_data *data)
{
	while(data->env != NULL)
    {
        printf("Var = %s\n",data->env->var);
        printf("Value = %s\n",data->env->value);
        printf("Orihin = %d\n",data->env->origin);
        data->env = data->env->next;
    }
}