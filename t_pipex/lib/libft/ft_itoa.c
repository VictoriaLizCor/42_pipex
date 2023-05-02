/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:06:44 by lilizarr          #+#    #+#             */
/*   Updated: 2022/10/01 13:44:18 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power_10(int power)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (i++ <= power)
		result *= 10;
	return (result);
}

static char	*create_string(int n_cpy, int s_size, int sign_char, int sign_num)
{
	char	*s;
	int		cnt;
	int		res;

	cnt = 0;
	s = ft_calloc((s_size + sign_char + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (sign_char == 2 && s)
	{
		s[cnt] = '-';
		cnt++;
		sign_num = -1;
	}
	while (--s_size >= 0)
	{
		res = (n_cpy / power_10(s_size)) * sign_num;
		n_cpy = n_cpy % (power_10(s_size));
		s[cnt] = res + '0';
		cnt++;
	}
	s[cnt] = (sign_num * n_cpy) + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		s_size;
	int		n_cpy;
	int		sign_char;
	int		sign_num;

	s_size = 0;
	sign_char = 1;
	n_cpy = n;
	sign_num = -1;
	if (n < 0)
	{
		sign_num = 1;
		sign_char++;
	}	
	while ((sign_num * n_cpy) <= -10)
	{
		n_cpy = n_cpy / 10;
		s_size++;
	}
	n_cpy = n * sign_num;
	return (create_string(n_cpy, s_size, sign_char, sign_num));
}
