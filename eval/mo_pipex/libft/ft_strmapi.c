/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:54:54 by mochan            #+#    #+#             */
/*   Updated: 2021/09/13 22:55:03 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	if (!(s == NULL || f == NULL))
	{
		i = ft_strlen((char *)s);
		dest = (char *)malloc((i + 1) * sizeof(*s));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
