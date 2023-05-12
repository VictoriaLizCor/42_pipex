/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:51:56 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/26 03:04:24 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(const char *fmt, va_list arg)
{
	int	len;

	if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X')
		len = ft_print_d_u_x(*fmt, arg);
	else if (*fmt == 'c')
		len = ft_character(arg);
	else if (*fmt == 's')
		len = ft_string(arg);
	else if (*fmt == 'p')
		len = ft_pointer(*fmt, va_arg(arg, size_t));
	else if (*fmt == '%')
		len = write(1, "%", 1);
	else
		len = 0;
	return (len);
}

int	ft_check_print(const char *fmt, va_list arg)
{
	int	count;
	int	pchr;

	count = 0;
	pchr = 0;
	while (fmt[count])
	{
		if (fmt[count] == '%')
		{
			count ++;
			pchr += ft_check_specifier(&fmt[count], arg);
		}
		else
			pchr += write(1, &fmt[count], 1);
		count ++;
	}
	return (pchr);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		pchr;

	if (!fmt)
	{
		ft_putstr_fd("(null)", 1);
		return (24);
	}
	if (!ft_strchr(fmt, '%'))
	{
		ft_putstr_fd((char *)fmt, 1);
		return ((int)ft_strlen(fmt));
	}
	va_start(ap, fmt);
	pchr = ft_check_print(fmt, ap);
	va_end(ap);
	return (pchr);
}
