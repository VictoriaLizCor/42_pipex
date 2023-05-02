/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 13:55:47 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** The strlcat() fappends string src to the end of dst.  It 
** will append at most dstsize - strlen(dst) - 1 characters.
** It will then NUL-terminate, unless dstsize is 0 or the 
** original dst string was longer than dstsize (in practice 
** this should not happen as it means that either dstsize is 
** incorrect or that dst is not a proper string).
** If the src and dst strings overlap, the behavior is undefined. 
** RETURN VALUES
** strlcat() functions return the total length of the string 
** they tried to create. For strlcat() that means the initial 
** length of dst plus the length of src.
** If the return value is >= dstsize, the output string has 
** been truncated.  It is the caller's responsibility to handle this.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		cnt;
	size_t		dlen;

	d = dest;
	s = src;
	cnt = n;
	while (cnt-- != 0 && *d)
		d++;
	dlen = d - dest;
	cnt = n - dlen;
	if (cnt == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (cnt != 1)
		{
			*d++ = *s;
			cnt--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
