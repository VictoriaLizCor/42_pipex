/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:48:25 by mochan            #+#    #+#             */
/*   Updated: 2021/09/13 22:48:34 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*src_char;
	char	*dest_char;

	i = 0;
	dest_char = (char *) dest;
	src_char = (char *) src;
	if (!dest_char && !src_char)
		return (NULL);
	while ((size_t)i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}
