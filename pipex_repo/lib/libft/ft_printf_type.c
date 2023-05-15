/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:31:14 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/05 16:43:06 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_str(t_printf **content, int *ret)
{
	(*content)->ptr = va_arg((*content)->args, char *);
	if (!((*content)->ptr))
	{
		ft_putstr("(null)");
		*ret = (*ret) + 6;
		return ;
	}
	ft_putstr((char *)(*content)->ptr);
	*ret = *ret + (int)ft_strlen((*content)->ptr);
}

void	ft_printf_int(t_printf **content, int *ret)
{
	char	*num;

	num = ft_itoa(va_arg((*content)->args, int));
	ft_putstr(num);
	*ret = *ret + (int)ft_strlen(num);
	free(num);
}

void	ft_printf_char(t_printf **content, int *ret)
{
	ft_putchar(va_arg((*content)->args, int));
	(*ret)++;
}

void	ft_printf_upx(t_printf **content, int *ret, int base)
{
	char			*upx_num;
	int				str_size;
	unsigned long	num;

	(*content)->ptr = va_arg((*content)->args, void *);
	if ((*content)->c_spc == 'p')
		num = (unsigned long)(*content)->ptr;
	else
		num = (unsigned long int)(*content)->ptr;
	str_size = ft_get_strsize(num, base);
	upx_num = ft_calloc(str_size + 1, sizeof(char));
	ft_convert2base(upx_num, str_size, base, num);
	if ((*content)->c_spc == 'p')
		upx_num = ft_strjoin_gnl("0x", upx_num, 2);
	if ((*content)->c_spc == 'X')
	{
		while (str_size--)
			*(upx_num + str_size) = ft_toupper(*(upx_num + str_size));
	}
	ft_putstr(upx_num);
	*ret = *ret + (int)ft_strlen(upx_num);
	free(upx_num);
}
