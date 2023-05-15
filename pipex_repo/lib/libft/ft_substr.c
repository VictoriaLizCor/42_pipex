/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/10 15:34:11 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	nlen;

	if (s)
	{
		if (ft_strlen(s) < len)
			nlen = ft_strlen(s);
		else
			nlen = len;
		st = ft_calloc(sizeof(char), nlen + 1);
		if (st)
		{
			if (start < ft_strlen(s))
				ft_memcpy(st, &s[start], nlen);
		}
		else
			return (NULL);
		return (st);
	}
	return ((char *)s);
}
