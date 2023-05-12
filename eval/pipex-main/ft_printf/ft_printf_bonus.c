/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 01:52:00 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 04:45:08 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_check_flags(const char *fmt, t_print *buff, va_list arg)
{
	while (*fmt == '0' || *fmt == '-' || *fmt == '.')
	{
		buff->ignore ++;
		if (*fmt == '-')
			buff->flag = *fmt;
		else if (buff->flag != '-' && *fmt == '0')
			buff->flag = *fmt;
		if (*fmt == '.')
		{
			fmt ++;
			buff->s_pres ++;
			ft_check_precision(fmt, buff, arg);
			return ;
		}
		fmt ++;
	}
	if (*fmt == '*')
		ft_check_width(fmt, buff, arg);
	else if (*fmt == ' ' || *fmt == '+' || *fmt == '#')
	{
		ft_extra_flags(fmt, buff, arg);
		return ;
	}
	else
		ft_check_width(fmt, buff, arg);
}

void	ft_extra_flags(const char *fmt, t_print *buff, va_list arg)
{
	while (*fmt == ' ' || *fmt == '+' || *fmt == '#')
	{
		buff->ignore ++;
		if (*fmt == '#')
			buff->flag2 = *fmt;
		else if (buff->flag2 != '#' && *fmt == '+')
			buff->flag2 = *fmt;
		else if (buff->flag2 != '#' && buff->flag2 != '+')
			buff->flag2 = *fmt;
		fmt ++;
	}
	if (*fmt == '*')
		ft_check_width(fmt, buff, arg);
	else if (*fmt == '0' || *fmt == '-' || *fmt == '.')
	{
		ft_check_flags(fmt, buff, arg);
		return ;
	}
	else
		ft_check_width(fmt, buff, arg);
}

int	ft_check_arg(const char *fmt, t_print *buff, va_list arg)
{
	if (*fmt == '0' || *fmt == '-' || *fmt == '.')
		ft_check_flags(fmt, buff, arg);
	else if (*fmt == '+' || *fmt == '#' || *fmt == ' ')
		ft_extra_flags(fmt, buff, arg);
	else if (*fmt >= '1' && *fmt <= '9')
		ft_check_width(fmt, buff, arg);
	else if (*fmt == '*')
		ft_check_width(fmt, buff, arg);
	else if (*fmt == '%')
	{
		buff->ignore += write(1, "%", 1);
		buff->pchr ++;
	}
	else
		ft_check_specifier(fmt, buff, arg);
	return (buff->pchr);
}

int	ft_check_print(const char *fmt, va_list arg)
{
	t_print	*buff;
	int		count;
	int		pchr;

	count = 0;
	pchr = 0;
	while (fmt[count])
	{
		if (fmt[count] == '%')
		{
			count ++;
			buff = (t_print *)ft_calloc(1, sizeof(t_print));
			if (!buff)
				return (0);
			pchr += ft_check_arg(&fmt[count], buff, arg);
			count += buff->ignore;
			free(buff);
		}
		else
		{
			pchr += write(1, &fmt[count], 1);
			count ++;
		}
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
