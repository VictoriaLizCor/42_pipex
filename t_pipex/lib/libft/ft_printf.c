/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:57:59 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/04 10:47:51 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_specifier(t_printf **content, const char *format, int *ret)
{
	(*content)->c_spc = (char)*format;
	if (*format == 's')
		ft_printf_str(&*content, ret);
	else if (ft_strchr("id", *format))
		ft_printf_int(&*content, ret);
	else if (*format == 'c')
		ft_printf_char(&*content, ret);
	else if (*format == 'p')
		ft_printf_upx(&*content, &*ret, 16);
	else if (ft_strchr("xX", *format))
		ft_printf_upx(&*content, &*ret, 16);
	else if (*format == 'u')
		ft_printf_upx(&*content, &*ret, 10);
	else if (*format == '%')
	{
		ft_putchar(*format);
		(*ret)++;
	}
}

int	ft_printf(const char *format, ...)
{
	static t_printf	*content;
	int				ret;

	ret = 0;
	content = (t_printf *)malloc(sizeof(t_printf));
	if (!content)
		content = NULL;
	va_start(content->args, format);
	while (*format)
	{
		if (*format == '%')
		{
			check_specifier(&content, (format + 1), &ret);
			format++;
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	va_end(content->args);
	free(content);
	return (ret);
}
