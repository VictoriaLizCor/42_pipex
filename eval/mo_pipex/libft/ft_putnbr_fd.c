/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:51:27 by mochan            #+#    #+#             */
/*   Updated: 2021/09/13 22:51:39 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	num;

	num = nb;
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num > 9 || num < -9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		ft_putchar_fd(num + '0', fd);
	}
}
