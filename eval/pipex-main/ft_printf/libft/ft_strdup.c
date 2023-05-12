/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:26:20 by melkholy          #+#    #+#             */
/*   Updated: 2022/02/08 05:43:44 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	count;
	size_t	len;

	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	count = 0;
	while (count < len)
	{
		dup[count] = str[count];
		count ++;
	}
	dup[count] = '\0';
	return (dup);
}
