/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:56:30 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/26 03:15:46 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_ncount_unsigned(unsigned int n);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_ncount_hex(size_t n);
char	*ft_to_hexstr(char speci, size_t n);
int		ft_character(va_list arg);
int		ft_string(va_list arg);
int		ft_pointer(char speci, size_t nbr);
int		ft_print_d_u_x(char speci, va_list arg);
int		ft_check_specifier(const char *fmt, va_list arg);
int		ft_check_print(const char *fmt, va_list arg);
int		ft_printf(const char *fmt, ...);

#endif
