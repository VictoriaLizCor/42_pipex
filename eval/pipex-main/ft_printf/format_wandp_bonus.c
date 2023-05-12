/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wandp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:01:46 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 07:57:39 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_width_andminus(t_print *buff, char *arg, int len)
{
	buff->extra = 0;
	buff->count = buff->pres;
	if (len > buff->pres)
		buff->count = len;
	if (arg && *arg == '-')
		buff->extra ++;
	if ((buff->flag2 == '+' && *arg != '-') || buff->flag2 == ' ')
		buff->count ++;
	else if (buff->flag2 == '#')
		buff->count += 2;
	if (buff->pres >= len)
		buff->count += buff->extra;
	while (--len >= buff->extra && \
			!(buff->s_pres && !buff->pres && arg[0] == '0'))
		buff->str[--buff->count] = arg[len];
	if (buff->flag2 == ' ' && *arg != '-')
		buff->str[0] = ' ';
	else if (buff->flag2 == '+' && *arg != '-')
		buff->str[0] = '+';
	else if (buff->flag2 == '+' || *arg == '-')
		buff->str[0] = '-';
	else if (buff->flag2 == '#' && buff->speci == 'x')
		buff->str[1] = 'x';
	else if (buff->flag2 == '#' && buff->speci == 'X')
		buff->str[1] = 'X';
}

void	ft_width_and_pres(t_print *buff, char *arg, int len)
{
	buff->extra = 0;
	buff->count = 0;
	if (arg && *arg == '-')
		buff->extra ++;
	while (--len >= buff->extra && \
			!(buff->s_pres && !buff->pres && arg[0] == '0'))
	{
		buff->str[--buff->width] = arg[len];
		buff->pres --;
	}
	if (len < buff->pres)
		buff->count = buff->pres;
	if (buff->flag2 == '+' && *arg != '-')
		buff->str[buff->width - buff->count - 1] = '+';
	else if (buff->flag2 == '+' || *arg == '-')
		buff->str[buff->width - buff->count - 1] = '-';
	else if (buff->flag2 == '#' && buff->speci == 'x')
		buff->str[buff->width - buff->count - 1] = 'x';
	else if (buff->flag2 == '#' && buff->speci == 'X')
		buff->str[buff->width - buff->count - 1] = 'X';
	if (buff->flag2 == '#')
		buff->str[buff->width - buff->count - 2] = '0';
}

void	ft_width_and_zero(t_print *buff, char *arg, int len)
{
	buff->extra = 0;
	buff->count = buff->width;
	if (*arg == '-')
		buff->extra ++;
	while (--len >= buff->extra && \
			!(buff->s_pres && !buff->pres && arg[0] == '0'))
		buff->str[--buff->count] = arg[len];
	if (buff->flag2 == ' ' && *arg != '-')
		buff->str[0] = ' ';
	else if (buff->flag2 == '+' && *arg != '-')
		buff->str[0] = '+';
	else if (buff->flag2 == '+' || *arg == '-')
		buff->str[0] = '-';
	else if (buff->flag2 == '#' && buff->speci == 'x')
		buff->str[1] = 'x';
	else if (buff->flag2 == '#' && buff->speci == 'X')
		buff->str[1] = 'X';
}

void	ft_fmt_width(t_print *buff, char *arg, int len)
{
	if (buff->flag == '0' && !buff->s_pres)
		ft_width_and_zero(buff, arg, len);
	else if (buff->flag == '-')
		ft_width_andminus(buff, arg, len);
	else
		ft_width_and_pres(buff, arg, len);
}

void	ft_fmt_pres(t_print *buff, char *arg, int len)
{
	int	count;
	int	str_len;

	count = 0;
	str_len = ft_strlen(buff->str);
	if (*arg == '-')
		count ++;
	if (buff->flag2 == '#' && buff->speci == 'x')
		buff->str[1] = 'x';
	else if (buff->flag2 == '#' && buff->speci == 'X')
		buff->str[1] = 'X';
	else if (buff->flag2 == '+' && *arg != '-')
		buff->str[0] = '+';
	else if (buff->flag2 == '+' || *arg == '-')
		buff->str[0] = '-';
	while (--len >= count)
		buff->str[--str_len] = arg[len];
}
