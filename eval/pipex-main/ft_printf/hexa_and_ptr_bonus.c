/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_and_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:00:00 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 08:00:11 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	ft_pointer(t_print *buff, size_t nbr)
{
	char	*str_nbr;
	int		len;

	if (nbr == 0)
	{
		ft_string(buff, "0x0");
		return ;
	}
	buff->speci = 'p';
	str_nbr = ft_to_hexstr('p', nbr);
	str_nbr[0] = '0';
	str_nbr[1] = 'x';
	len = ft_strlen(str_nbr);
	if (buff->width > len)
	{
		ft_strallo_width(buff, str_nbr, len);
		ft_fmt_width(buff, str_nbr, len);
		buff->pchr += write(1, buff->str, ft_strlen(buff->str));
		free(buff->str);
	}
	else
		buff->pchr += write(1, str_nbr, len);
	free(str_nbr);
}

void	ft_hexadecimal(const char *fmt, t_print *buff, unsigned int nbr)
{
	char	*str_nbr;
	int		len;

	if (!nbr && buff->s_pres && !buff->pres & !buff->width)
		return ;
	buff->speci = *fmt;
	str_nbr = ft_to_hexstr(*fmt, nbr);
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
	{
		if (buff->flag2 == '#' && nbr)
			buff->pchr += write(1, "0", 1) + write(1, &(*fmt), 1);
		buff->pchr += write(1, str_nbr, ft_strlen(str_nbr));
	}
	free(str_nbr);
}
