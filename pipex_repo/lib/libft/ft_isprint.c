/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/27 16:46:37 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The isprint() function tests for any printing character, 
** including space (` ').
** The value of the argument must be representable as an 
** unsigned char or the value of EOF.
** RETURN VALUES
** The isprint() function returns zero if the character tests false and returns 
** non-zero if the character tests true.
*/
int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}
