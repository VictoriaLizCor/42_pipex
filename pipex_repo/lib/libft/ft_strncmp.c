/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/09/28 13:43:38 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The strncmp() functions lexicographically compare the 
** null-terminated strings s1 and s2.
** The strncmp() function compares not more than n characters.  
** Because strncmp() is designed for comparing strings rather 
** than binary data, characters that appear after a `\0'
**  character are not compared.
** RETURN VALUES
** The strncmp() functions return an integer greater than, 
** equal to, or less than 0, according as the string s1 is 
** greater than, equal to, or less than the string s2.  
** The comparison is done using unsigned characters, so that 
** `\200' is greater than `\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	cnt;

	cnt = 0;
	if (n > 0)
	{
		while (cnt + 1 < n && (s1[cnt]) && (s2[cnt]) && s1[cnt] == s2[cnt])
		{
			cnt++;
		}
		if ((unsigned char)(s1[cnt]) - (unsigned char)(s2[cnt]) > 0)
			return (1);
		else if ((unsigned char)(s1[cnt]) - (unsigned char)(s2[cnt]) < 0)
			return (-1);
		else
			return (0);
	}
	else
		return (0);
}
