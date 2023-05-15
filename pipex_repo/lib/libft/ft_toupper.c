/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 15:57:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* DESCRIPTION
The toupper() function converts a lower-case letter to 
the corresponding upper-case letter.  The argument must 
be representable as an unsigned char or the value of OF.

RETURN VALUES
If the argument is a lower-case letter, the toupper() 
function returns the corresponding upper-case letter if 
there is one; otherwise, the argument is returned 
unchanged. */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
