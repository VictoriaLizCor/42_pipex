/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:52:30 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 22:29:24 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (*(s + i))
	{
		if (*(s + i) && *(s + (i + 1)) != c && (s + (i + 1)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**string;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	string = ft_calloc(ft_count((char *)s, c) + 1, sizeof(char *));
	if (!string)
		return (NULL);
	while (*(s + start))
	{
		while (*(s + start) == c && *(s + start))
			start++;
		end = start;
		while (*(s + end) != c && *(s + end))
			end++;
		if (*(s + start))
			string[i] = ft_substr(s, start, end - start);
		i++;
		start = end;
	}
	return (string);
}
