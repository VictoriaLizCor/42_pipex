/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_width_prec_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 01:56:20 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 06:51:50 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_strallo_width(t_print *buff, char *arg, int len)
{
	buff->count = 0;
	if (buff->flag2 == '#' && ((buff->width - len) == 1 \
		|| (buff->width - buff->pres) == 1))
		buff->width ++;
	buff->str = (char *)ft_calloc(buff->width + 1, sizeof(char));
	while (buff->flag == '0' && !buff->s_pres && buff->count < buff->width)
		buff->str[buff->count++] = '0';
	while (buff->count < buff->width)
		buff->str[buff->count++] = ' ';
	if (buff->pres && buff->flag != '-' && len <= buff->pres)
	{
		buff->count = buff->width - buff->pres;
		while (buff->count < buff->width)
			buff->str[buff->count++] = '0';
	}
	else if (buff->pres && buff->flag == '-' && len <= buff->pres)
	{
		buff->count = buff->pres;
		if (arg && (buff->flag2 == ' ' || buff->flag2 == '+' || *arg == '-'))
			buff->count ++;
		else if (buff->flag2 == '#')
			buff->count += 2;
		while (--buff->count >= 0)
			buff->str[buff->count] = '0';
	}
}

void	ft_strallo_pres(t_print *buff, char *arg)
{
	int	count;
	int	fill;

	count = 0;
	fill = -1;
	if (buff->flag2 == '#')
		count += 2;
	else if (arg && (buff->flag2 == '+' || *arg == '-' || buff->flag2 == ' '))
		count ++;
	buff->str = (char *)ft_calloc(buff->pres + count + 1, sizeof(char));
	if (buff->flag2 == ' ')
		buff->str[++fill] = ' ';
	while (++fill < (buff->pres + count))
		buff->str[fill] = '0';
}

void	ft_stralloc(t_print *buff, char *arg)
{
	int	len;

	if (arg)
		len = ft_strlen(arg);
	else
		len = 0;
	if (buff->width >= len || buff->pres >= len)
	{
		if (buff->pres >= buff->width)
			ft_strallo_pres(buff, arg);
		else
			ft_strallo_width(buff, arg, len);
	}
}
