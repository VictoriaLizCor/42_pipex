/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/08 19:30:11 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** DESCRIPTION
** The atoi() function converts the initial portion of the 
** string pointed to by str to int representation.
*/
// INT_MIN = 				-2,147,483,648
// UINT_MAX					 4,294,967,295
// LONG_MAX =    9,223,372,036,854,775,807
// ULLONG_MAX = 18,446,744,073,709,551,615
static int	max_values(unsigned long long *num, int *sign, char c)
{
	if (*num > LONG_MAX || ft_isdigit(c))
	{
		if (*sign == 1)
			return (-1);
		else
			return (0);
	}
	return ((int)(*num * *sign));
}

int	ft_atoi(const char *s)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	if (ft_strlen(s) == 0)
		return ((int)num * sign);
	while (*s != '\0' && (ft_isdigit(*s) || ft_strchr(" +-\t\n\r\v\f", *s) != NULL))
	{	
		if (num == 0 && *s == '-')
			sign = -1;
		if (ft_isdigit(*s))
		{
			num = num * 10 + (*s - '0');
			if (num / 100000000000000000 > 10)
				return (max_values(&num, &sign, *(s + 1)));
		}
		else if (num > 0)
			return ((int)num * sign);
		if ((*s == '+' || *s == '-') && ft_strchr(" +-\t\n\r\v\f", *(s + 1)))
			return (0);
		s++;
	}
	return ((int)num * sign);
}
