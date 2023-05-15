/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/26 15:25:23 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			idx;
	char		*str;

	idx = 0;
	if (s)
	{
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
		if (str)
		{
			while (s[idx])
			{
				str[idx] = (*f)(idx, s[idx]);
				idx++;
			}
		}
		return (str);
	}
	return ((char *)s);
}
