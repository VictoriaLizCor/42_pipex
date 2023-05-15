/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 13:39:38 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** The strrchr() function locates the last occurrence of c.
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the
** located character, or NULL if the character does not appear 
** in the string.
*/
char	*ft_strrchr(const char *s, int c)
{	
	size_t	cnt;

	cnt = ft_strlen(s);
	while (cnt > 0)
	{
		if (*(s + cnt) == (char)c || !c)
			return ((char *)(s + cnt));
		cnt--;
	}
	if (cnt == 0 && (char)c == *s)
		return ((char *)s);
	return (NULL);
}
