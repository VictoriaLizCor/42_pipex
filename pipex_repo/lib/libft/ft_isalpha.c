/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 16:38:46 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
** DESCRIPTION
** The isalpha() function tests for any character for 
** which isupper(3) or islower(3) is true.  The value of 
** the argument must be representable as an unsigned char or 
** the value of EOF.
** RETURN VALUES
** The isalpha() function returns zero if the character tests 
** false and returns non-zero if the 
** character tests true. 
*/
int	ft_isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return (1);
	return (0);
}
