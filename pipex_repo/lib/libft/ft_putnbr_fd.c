/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/01 13:14:41 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}
