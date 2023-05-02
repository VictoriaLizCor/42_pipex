/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/05 09:56:50 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The strnstr() function locates the first occurrence of the 
** null-terminated string needle in the string haystack, where 
** not more than len characters are searched.  Characters that 
** appear after a `\0' character are not searched. 
** RETURN VALUES
** If needle is an empty string, haystack is returned; if 
** needle occurs nowhere in haystack, NULL is returned; 
** otherwise a pointer to the first character of the first 
** occurrence of needle is returned.
*/
char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	j;
	size_t	i;

	if (!*nd)
		return ((char *)hs);
	if (len > 0 && ft_strchr(hs, nd[0]) != NULL)
	{
		j = 0;
		i = -1;
		while (nd[++i] && len > 0 && i + j <= ft_strlen(hs))
		{
			if (nd[i] != hs[j + i])
			{
				j++;
				i = -1;
			}
		}
		if (i == ft_strlen(nd) && i + j <= len)
			return ((char *)hs + j);
	}
	return (NULL);
}
