/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 16:40:14 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
** DESCRIPTION
** The isalnum() function tests for any character for which isalpha(3) or
** isdigit(3) is true.  The value of the argument must be representable as 
** an unsigned char or the value of EOF.
** In the ASCII character set, this includes the following characters (int)
** between [65, 90], [97, 122] && [48, 57]
** RETURN VALUES
** The isalnum() function returns zero if the character tests false and 
** returns non-zero if the character tests true. 
*/
int	ft_isalnum(int ch)
{
	if (ft_isalpha(ch) || ft_isdigit(ch))
		return (1);
	return (0);
}
