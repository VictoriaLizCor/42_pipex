/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 17:22:38 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The memchr() function locates the first occurrence of c (converted to 
** an unsigned char) in string s.
** RETURN VALUES
** The memchr() function returns a pointer to the byte located, or 
** NULL if no such byte exists within n bytes.
*/
void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (*(ptr + i) == ((unsigned char)c))
			return ((void *)(ptr + i));
		i++;
	}
	if (*(ptr + (i - 1)) && ((unsigned char)c == 0))
		return ((void *)ptr);
	else
		return (NULL);
}
