/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:57:54 by mochan            #+#    #+#             */
/*   Updated: 2021/09/13 22:51:54 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int	num;

	num = nb;
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9 || num < -9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
	}
}
