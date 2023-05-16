/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:01:28 by mochan            #+#    #+#             */
/*   Updated: 2021/09/13 22:02:22 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	*ft_memalloc2(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (!(temp))
		return (NULL);
	ft_bzero(temp, size);
	return (temp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = (void *)ft_memalloc2(size * nmemb);
	if (!(tab))
		return (NULL);
	return (tab);
}
