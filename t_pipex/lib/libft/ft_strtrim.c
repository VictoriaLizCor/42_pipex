/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/15 17:07:07 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	size_t	s_st;
	size_t	e_st;

	if (set && s1)
	{
		s_st = 0;
		e_st = ft_strlen(s1) - 1;
		while (s1[s_st] && ft_strchr((set), s1[s_st]) && *set)
			s_st++;
		while (e_st > s_st && ft_strrchr((set), s1[e_st]) && *set && *s1)
			e_st--;
		st = (char *)malloc(e_st - s_st + 2);
		if (st)
		{
			ft_memcpy(st, s1 + s_st, e_st - s_st + 1);
			st[e_st - s_st + 1] = 0;
			return ((char *)st);
		}
		else
			return (NULL);
	}
	else
		return ((char *)s1);
}
