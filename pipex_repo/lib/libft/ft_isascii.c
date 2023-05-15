/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 16:44:09 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The isascii() function tests for an ASCII character, 
** which is any character between [0 - 127]
** RETURN VALUES
** The isascii() function returns zero if the character tests 
** false and returns non-zero if the character tests true. 
*/
int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	return (0);
}
