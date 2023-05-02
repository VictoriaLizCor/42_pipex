/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 11:23:00 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
** The memmove() function copies length bytes from the buffer pointed 
** to by src to the buffer pointed to by dst. Copying of overlapping 
** regions is handled safely. Use memcpy() for greater speed when copying 
** buffers that don't overlap 
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pd;
	char	*ps;

	pd = (char *)dest;
	ps = (char *)src;
	if (dest != src && n)
	{
		if (src < dest)
		{
			while (n--)
				*(pd + n) = *(ps + n);
		}
		else
		{
			while (n--)
				*pd++ = *ps++;
		}
	}
	return (dest);
}
