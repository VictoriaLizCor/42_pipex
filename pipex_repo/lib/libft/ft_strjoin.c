/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/15 17:08:02 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;

	if (s1 && s2)
	{
		sj = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (sj)
		{
			ft_memcpy(sj, s1, ft_strlen(s1));
			ft_memcpy(sj + ft_strlen(s1), s2, ft_strlen(s2) + 1);
			return ((char *)sj);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
