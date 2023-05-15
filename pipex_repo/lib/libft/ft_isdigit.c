/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 16:37:38 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The isdigit() function tests for a decimal digit character.
** Regardless of locale, this includes the following characters only:
** [0 - 9]
** The value of the argument must be representable as an unsigned char 
** or the value of EOF.
** RETURN VALUES
** The isdigit() and isnumber() functions return zero if the 
** character tests false and return non-zero if the character tests true.
*/
int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
