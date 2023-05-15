/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/02 14:30:05 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s_i = string_index
// s_l = string_lenght
// a_cnt = array_counter
static void	ft_free_split(char **split, int *a_cnt, int *s_i)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
	free(split);
	*a_cnt = -1;
	*s_i = 0;
}

static char	**fill_array(const char *s, char c, char **split)
{
	int	a_cnt;
	int	s_i;
	int	s_l;

	a_cnt = 0;
	s_l = 0;
	s_i = 0;
	while (s[s_i])
	{
		if (s[s_i] != c)
			s_l++;
		if (s[s_i] != c && (s[s_i + 1] == 0 || s[s_i + 1] == c))
		{
			split[a_cnt] = ft_substr(s, s_i - s_l + 1, s_l);
			if (!split[a_cnt])
				ft_free_split(split, &a_cnt, &s_i);
			s_l = 0;
			a_cnt++;
		}
		s_i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		a_size;
	int		s_i;

	if (!s)
		return (NULL);
	s_i = 0;
	a_size = 1;
	while (s[s_i])
	{
		if (s[s_i] != c && (s[s_i + 1] == '\0' || s[s_i + 1] == c))
			a_size++;
		s_i++;
	}
	split = ft_calloc(sizeof(char *), (a_size));
	if (!split)
		return (NULL);
	if (a_size > 1)
		fill_array(s, c, split);
	else
		split[0] = NULL;
	return (split);
}
