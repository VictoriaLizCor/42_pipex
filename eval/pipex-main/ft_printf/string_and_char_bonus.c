/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_and_char_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:47:33 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 18:17:26 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

void	ft_format_s(t_print *buff, char *str, int len)
{
	buff->count = -1;
	if (buff->flag == '-')
	{
		if (buff->s_pres)
			while (++buff->count < buff->pres)
				buff->str[buff->count] = str[buff->count];
		else
		{
			while (str[++buff->count])
				buff->str[buff->count] = str[buff->count];
		}
	}
	else
	{
		buff->count = ft_strlen(buff->str);
		if (buff->s_pres)
			while (--buff->pres >= 0)
				buff->str[--buff->count] = str[buff->pres];
		else
			while (--len >= 0)
				buff->str[--buff->count] = str[len];
	}
}

void	ft_width_and_s(t_print *buff, char *str, int len)
{
	if ((buff->pres > buff->width && buff->pres > len) || buff->pres > len)
		buff->pres = len;
	ft_stralloc(buff, NULL);
	ft_format_s(buff, str, len);
	buff->pchr += write(1, buff->str, ft_strlen(buff->str));
	free(buff->str);
}

void	ft_pres_and_s(t_print *buff, char *str, int len)
{
	if (buff->s_pres && buff->pres < len)
	{
		if (buff->pres == 0)
			return ;
		ft_stralloc(buff, NULL);
		buff->count = -1;
		while (++buff->count < buff->pres)
			buff->str[buff->count] = str[buff->count];
		buff->pchr += write(1, buff->str, ft_strlen(buff->str));
		free(buff->str);
	}
	else
		buff->pchr += write(1, str, len);
}

void	ft_character(t_print *buff, va_list arg)
{
	char	c;
	int		count;

	c = va_arg(arg, int);
	count = -1;
	if (!buff->width)
	{
		write(1, &c, 1);
		buff->pchr ++;
	}
	else
	{
		buff->str = (char *)ft_calloc(buff->width + 1, sizeof(char));
		while (++count < buff->width)
			buff->str[count] = ' ';
		if (buff->flag == '-')
			buff->str[0] = c;
		else
			buff->str[ft_strlen(buff->str) - 1] = c;
		write(1, buff->str, buff->width);
		buff->pchr += buff->width;
		free(buff->str);
	}
}

void	ft_string(t_print *buff, char *str)
{
	int		len;

	buff->speci = 's';
	if (!str)
	{
		str = ft_strdup("(null)");
		buff->s_null ++;
	}
	len = ft_strlen(str);
	if (buff->width > len || (buff->width && buff->s_pres))
		ft_width_and_s(buff, str, len);
	else
		ft_pres_and_s(buff, str, len);
	if (buff->s_null)
		free(str);
}
