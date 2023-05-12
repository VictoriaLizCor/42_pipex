/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:26:35 by melkholy          #+#    #+#             */
/*   Updated: 2022/08/27 08:04:54 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_print
{
	char	*str;
	char	flag;
	char	flag2;
	char	speci;
	int		s_pres;
	int		s_null;
	int		width;
	int		pres;
	int		count;
	int		pchr;
	int		ignore;
	int		extra;
}			t_print;

int		ft_ncount_unsigned(unsigned int n);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_ncount_hex(size_t n);
char	*ft_to_hexstr(char speci, size_t n);
void	ft_nopres_flag2(t_print *buff, char *str_num);
void	ft_width_andminus(t_print *buff, char *arg, int len);
void	ft_width_and_pres(t_print *buff, char *arg, int len);
void	ft_width_and_zero(t_print *buff, char *arg, int len);
void	ft_fmt_width(t_print *buff, char *arg, int len);
void	ft_fmt_pres(t_print *buff, char *arg, int len);
void	ft_strallo_width(t_print *buff, char *arg, int len);
void	ft_strallo_pres(t_print *buff, char *arg);
void	ft_stralloc(t_print *buff, char *arg);
void	ft_format_s(t_print *buff, char *str, int len);
void	ft_width_and_s(t_print *buff, char *str, int len);
void	ft_pres_and_s(t_print *buff, char *str, int len);
void	ft_integer(t_print *buff, int num);
void	ft_character(t_print *buff, va_list arg);
void	ft_string(t_print *buff, char *str);
void	ft_pointer(t_print *buff, size_t nbr);
void	ft_unsigned_int(t_print *buff, unsigned int nbr);
void	ft_hexadecimal(const char *fmt, t_print *buff, unsigned int nbr);
void	ft_check_specifier(const char *fmt, t_print *buff, va_list arg);
void	ft_check_star(int check, t_print *buff, va_list arg);
void	ft_check_precision(const char *fmt, t_print *buff, va_list arg);
void	ft_check_width(const char *fmt, t_print *buff, va_list arg);
void	ft_extra_flags(const char *fmt, t_print *buff, va_list arg);
void	ft_check_flags(const char *fmt, t_print *buff, va_list arg);
int		ft_check_arg(const char *fmt, t_print *buff, va_list arg);
int		ft_check_print(const char *fmt, va_list arg);
int		ft_printf(const char *fmt, ...);

#endif
