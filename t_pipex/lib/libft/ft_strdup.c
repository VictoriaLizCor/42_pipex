/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 13:58:16 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The strdup() function allocates sufficient memory for a copy
** of the string s1, does the copy, and returns a pointer to 
** it. The pointer may subsequently be used as an argument to 
** the function free(3).
** If insufficient memory is available, NULL is returned. 
** The strndup() function copies at most n characters from 
** the string s1 always NUL terminating the copied string.
*/
char	*ft_strdup(const char *s1)
{
	void	*aux;

	aux = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (aux == NULL)
		return (0);
	aux = ft_memcpy(aux, s1, ft_strlen(s1));
	((char *)aux)[ft_strlen(s1)] = '\0';
	return (aux);
}
