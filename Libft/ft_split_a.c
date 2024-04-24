/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:16:19 by sylabbe           #+#    #+#             */
/*   Updated: 2024/04/03 17:57:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**create_tab(t_alloc **lst_alloc, const char *s, char c, char **tab)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	tab = malloc((count + 1) * sizeof(char *));
	if (add_alloc(lst_alloc, NULL, (void **)tab))
		return (NULL);
	return (tab);
}

static char	*create_str(t_alloc **lst_alloc, const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start + 1) * sizeof(char));
	if (add_alloc(lst_alloc, str, NULL))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**errfree(t_alloc **lst_alloc)
{
	rm_lst_alloc(*lst_alloc, NULL);
	return (NULL);
}

static char	**fill_tab(t_alloc **lst_alloc, const char *s, char c, char **res)
{
	int	i;
	int	count;
	int	start;

	i = 0;
	start = 0;
	count = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			start = i + 1;
		else if (s[i + 1] == c || s[i + 1] == '\0')
		{
			count++;
			res[count] = create_str(lst_alloc, s, start, i + 1);
			if (res[count] == NULL)
				return (errfree(lst_alloc));
		}
		i++;
	}
	res[count + 1] = NULL;
	return (res);
}

char	**ft_split_a(t_alloc **lst_alloc, char const *s, char c)
{
	char	**res;

	res = NULL;
	if (s == NULL)
		return (NULL);
	res = create_tab(lst_alloc, s, c, res);
	if (res == NULL)
		return (NULL);
	fill_tab(lst_alloc, s, c, res);
	return (res);
}
