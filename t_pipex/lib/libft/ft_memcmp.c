/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 17:43:51 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** RETURN VALUES
** The memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes
** (treated asunsigned char values, so that `\200' is greater than `\0', 
** for example).  Zero-length strings are always identical.  This behavior is
** not required by C and portable code should only depend on the sign of the
** returned value.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	if (n > 0)
	{
		while (--n > 0 && ptr1[i] == ptr2[i])
			i++;
		if (ptr1[i] - ptr2[i] != 0)
			return (ptr1[i] - ptr2[i]);
	}
	return (0);
}
