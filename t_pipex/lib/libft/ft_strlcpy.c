/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 13:36:30 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The strlcpy() function copy and concatenate strings, taking
** the full size of the destination buffer and guarantee 
** NUL-termination if there is room.
**  Note that room for the NUL should be included in dstsize.
** strlcpy() copies up to dstsize - 1 characters from the 
** string src to dst, NUL-terminating the result if dstsize is not 0.
** If the src and dst strings overlap, the behavior is undefined.
** RETURN VALUES
** Strlcpy() function return the total length of the string 
** they tried to create. For strlcpy() that means the length of src.
** If the return value is >= dstsize, the output string has 
** been truncated.  It is the caller's responsibility to handle this.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < n)
	{
		ft_memcpy(dest, src, src_len + 1);
	}
	else if (n != 0)
	{	
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (src_len);
}
