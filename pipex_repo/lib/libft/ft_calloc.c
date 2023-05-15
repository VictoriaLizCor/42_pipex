/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/08 19:04:27 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The calloc() function contiguously allocates enough space 
** for count objects that are size bytes of memory each and 
** returns a pointer to the allocated memory.  The allocated
** memory is filled with bytes of value zero.
** RETURN VALUES
** If successful, it returns a pointer to allocated memory.  If 
** there is an error, it returns a NULL pointer.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	if (size == SIZE_MAX || count == SIZE_MAX)
		return (NULL);
	data = malloc(count * size);
	if (data)
		ft_bzero(data, count * size);
	else
		return (NULL);
	return (data);
}
