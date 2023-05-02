/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 11:21:19 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The memcpy() function copies n bytes from memory area src to memory area
** dst.  If dst and src overlap, behavior is undefined.  Applications in 
** which dst and src might overlap should use memmove(3) instead.
** RETURN VALUES
** The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (n-- && (dest != NULL || src != NULL))
	{
		((char *)dest)[i - n] = (*(const char *)(src + (i - n)));
	}
	return (dest);
}
