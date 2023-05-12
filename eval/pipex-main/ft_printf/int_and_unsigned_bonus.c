/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_and_unsigned_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:55:08 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 07:40:09 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	ft_nopres_flag2(t_print *buff, char *str_num)
{
	if (buff->flag2 == '+' && *str_num != '-')
	{
		ft_putchar_fd('+', 1);
		buff->pchr ++;
	}
	else if (buff->flag2 == ' ' && *str_num != '-')
	{
		ft_putchar_fd(' ', 1);
		buff->pchr ++;
	}
}

void	ft_unsigned_int(t_print *buff, unsigned int nbr)
{
	char	*str_nbr;
	int		len;

	if (!nbr && buff->s_pres && !buff->pres & !buff->width)
		return ;
	str_nbr = ft_itoa_unsigned(nbr);
	len = ft_strlen(str_nbr);
	ft_stralloc(buff, str_nbr);
	if (buff->str && ((int)ft_strlen(buff->str) - len) >= 0)
	{
		if (buff->pres >= buff->width)
			ft_fmt_pres(buff, str_nbr, len);
		else
			ft_fmt_width(buff, str_nbr, len);
		buff->pchr += write(1, buff->str, ft_strlen(buff->str));
		free(buff->str);
	}
	else
		buff->pchr += write(1, str_nbr, ft_strlen(str_nbr));
	free(str_nbr);
}

void	ft_integer(t_print *buff, int num)
{
	char	*str_num;

	if (!num && buff->s_pres && !buff->pres && !buff->width)
		return ;
	str_num = ft_itoa(num);
	ft_stralloc(buff, str_num);
	if (buff->str && ((int)ft_strlen(buff->str) - (int)ft_strlen(str_num)) >= 0)
	{
		if (buff->pres >= buff->width)
			ft_fmt_pres(buff, str_num, ft_strlen(str_num));
		else
			ft_fmt_width(buff, str_num, ft_strlen(str_num));
		ft_putstr_fd(buff->str, 1);
		buff->pchr += ft_strlen(buff->str);
		free(buff->str);
	}
	else
	{
		if (buff->flag2)
			ft_nopres_flag2(buff, str_num);
		ft_putstr_fd(str_num, 1);
		buff->pchr += ft_strlen(str_num);
	}
	free(str_num);
}
