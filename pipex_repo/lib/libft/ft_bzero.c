/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 17:21:05 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
/*
** DESCRIPTION
** The bzero() function erases the data in the n bytes of the memory
** starting at the location pointed to by s, by writing zeros (bytes
** containing '\0') to that area.
**  If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
