/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:48:07 by mochan            #+#    #+#             */
/*   Updated: 2021/09/13 22:48:17 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int len)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *) s1;
	q = (unsigned char *) s2;
	if (len == 0)
	{
		return (0);
	}
	while (*p == *q && len-- > 0)
	{
		p++;
		q++;
		if (len == 0)
			return (0);
	}
	if (*p != *q)
	{
		return (*p - *q);
	}
	return (0);
}
