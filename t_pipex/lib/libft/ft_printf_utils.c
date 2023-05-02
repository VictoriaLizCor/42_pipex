/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:01:55 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:46:14 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

int	ft_get_strsize(unsigned long num, int base)
{
	unsigned long	quotient;
	int				str_size;

	if (num == 0)
		return (1);
	str_size = 0;
	quotient = num;
	while (quotient > 0)
	{
		quotient = quotient / base;
		str_size++;
	}
	return (str_size);
}

void	ft_convert2base(char *str, int len, int base, unsigned long num)
{
	long long	remainder;

	while (len--)
	{
		remainder = num % base;
		if (remainder < 10)
			*(str + len) = '0' + remainder;
		else
			*(str + len) = 87 + remainder;
		num = num / base;
	}
}
