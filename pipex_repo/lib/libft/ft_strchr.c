/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 17:10:16 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The strchr() function locates the first occurrence of c (converted to a 
** char) in the string pointed to by s.  The terminating null character is 
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(*s) && !c)
		return ((char *)s);
	return (NULL);
}
