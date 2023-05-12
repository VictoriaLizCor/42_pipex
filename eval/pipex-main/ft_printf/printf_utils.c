/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:54:08 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/26 06:15:36 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ncount_unsigned(unsigned int n)
{
	unsigned int	temp;
	int				count;

	count = 0;
	if (n == 0)
		return (1);
	temp = n;
	while (temp)
	{
		temp /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		count;
	char	*num;

	count = ft_ncount_unsigned(n);
	num = (char *)malloc(count + 1 * sizeof(char));
	if (!num)
		return (NULL);
	num[count] = '\0';
	while (--count >= 0 || n)
	{
		num[count] = (n % 10) + 48;
		n /= 10;
	}
	return (num);
}

int	ft_ncount_hex(size_t n)
{
	int		count;
	size_t	temp;

	count = 0;
	if (n == 0)
		return (1);
	temp = n;
	while (temp)
	{
		temp /= 16;
		count ++;
	}
	return (count);
}

char	*ft_to_hexstr(char speci, size_t n)
{
	int		count;
	int		ptr;
	char	*num;
	char	*base;

	ptr = 0;
	if (speci == 'p')
		ptr = 2;
	if (speci == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = ft_ncount_hex(n);
	count += ptr;
	num = (char *)malloc(count + 1 * sizeof(char));
	if (!num)
		return (NULL);
	num[count] = '\0';
	while (--count >= 0 || n)
	{
		num[count] = base[n % 16];
		n /= 16;
	}
	return (num);
}
