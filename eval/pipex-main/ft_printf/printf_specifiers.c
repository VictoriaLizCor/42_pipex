/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:53:15 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/26 03:45:34 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_character(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}

int	ft_string(va_list arg)
{
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (str)
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
	else
		len = write(1, "(null)", 6);
	return (len);
}

int	ft_pointer(char speci, size_t nbr)
{
	char	*str_nbr;
	int		len;

	if (nbr == 0)
		return (write(1, "0x0", 3));
	str_nbr = ft_to_hexstr(speci, nbr);
	str_nbr[0] = '0';
	str_nbr[1] = 'x';
	len = ft_strlen(str_nbr);
	write(1, str_nbr, len);
	free(str_nbr);
	return (len);
}

int	ft_print_d_u_x(char speci, va_list arg)
{
	unsigned int	nbr;
	int				num;
	char			*str_nbr;
	int				len;

	if (speci == 'd' || speci == 'i')
	{
		num = va_arg(arg, int);
		str_nbr = ft_itoa(num);
	}
	else
		nbr = va_arg(arg, unsigned int);
	if (speci == 'x' || speci == 'X')
		str_nbr = ft_to_hexstr(speci, nbr);
	else if (speci == 'u')
		str_nbr = ft_itoa_unsigned(nbr);
	len = ft_strlen(str_nbr);
	write(1, str_nbr, len);
	free(str_nbr);
	return (len);
}
