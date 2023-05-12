/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_width_prec_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:06:48 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 08:09:53 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_check_specifier(const char *fmt, t_print *buff, va_list arg)
{
	buff->ignore ++;
	if (*fmt == 'd' || *fmt == 'i')
		ft_integer(buff, va_arg(arg, int));
	else if (*fmt == 'c')
		ft_character(buff, arg);
	else if (*fmt == 's')
		ft_string(buff, va_arg(arg, char *));
	else if (*fmt == 'p')
		ft_pointer(buff, va_arg(arg, size_t));
	else if (*fmt == 'u')
		ft_unsigned_int(buff, va_arg(arg, unsigned int));
	else if (*fmt == 'x' || *fmt == 'X')
		ft_hexadecimal(fmt, buff, va_arg(arg, unsigned int));
	else
		return ;
}

void	ft_check_star(int check, t_print *buff, va_list arg)
{
	if (check)
	{
		buff->pres = va_arg(arg, int);
		if (buff->pres < 0)
			buff->s_pres = 0;
	}
	else
	{
		buff->width = va_arg(arg, int);
		if (buff->width < 0)
		{
			buff->width *= -1;
			buff->flag = '-';
		}
	}
}

void	ft_check_precision(const char *fmt, t_print *buff, va_list arg)
{
	int	count;

	count = 0;
	if (*fmt == '*')
	{
		ft_check_star(1, buff, arg);
		count ++;
	}
	else
	{
		buff->pres = ft_atoi(fmt);
		while (fmt[count] >= '0' && fmt[count] <= '9')
			count ++;
	}
	buff->ignore += count;
	ft_check_specifier(&fmt[count], buff, arg);
}

void	ft_check_width(const char *fmt, t_print *buff, va_list arg)
{
	int	count;

	count = 0;
	if (*fmt == '*')
	{
		ft_check_star(0, buff, arg);
		count ++;
	}
	else
	{
		buff->width = ft_atoi(fmt);
		while (fmt[count] >= '0' && fmt[count] <= '9')
			count ++;
	}
	buff->ignore += count;
	if (fmt[count] == '.')
	{
		count ++;
		buff->ignore ++;
		buff->s_pres ++;
		ft_check_precision(&fmt[count], buff, arg);
	}
	else
		ft_check_specifier(&fmt[count], buff, arg);
}
