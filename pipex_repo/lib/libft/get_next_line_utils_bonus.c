/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:35:09 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/04 14:31:27 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_len(char *s1, size_t n)
{
	char	*aux;

	aux = (char *)malloc(n + 1);
	if (aux == NULL)
		return (NULL);
	aux = ft_memcpy(aux, s1, n);
	aux[n] = '\0';
	return (aux);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, int free_str)
{
	char	*sj;

	if (s1 && s2)
	{
		sj = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (sj)
		{
			ft_memcpy(sj, s1, ft_strlen(s1));
			ft_memcpy(sj + ft_strlen(s1), s2, ft_strlen(s2) + 1);
			if (free_str == 1)
				free((void *)s1);
			else if (free_str == 2)
				free((void *)s2);
			else
			{
				free((void *)s1);
				free((void *)s2);
			}
			return ((char *)sj);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
