/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:11:22 by droly             #+#    #+#             */
/*   Updated: 2016/04/25 17:06:03 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			diese;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flags;

typedef struct	s_printf
{
	int			field;
	int			precision;
	char		*len_modif;
	char		type;
	int			i;
	int			i2;
	int			tmp;
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		seek_len_modif_types(t_printf *lst, const char *format, int i);
t_printf		seek_field_precision(t_printf *lst, const char *format, int i);
t_flags			seek_flags(t_flags *lst2, char *t);
t_printf		seek_types(t_printf *lst, const char *format, va_list argptr,
		t_flags *lst2);
t_printf		apply_flags(t_printf *lst, t_flags *lst2, va_list argptr,
		char *str);
char			*put_in_maj(char *str);
char			*take_type1(t_printf *lst, t_flags *lst2, char *str,
		va_list argptr);
char			*take_type2(t_printf *lst, char *str, va_list argptr);
char			*apply_diese(t_printf *lst, char *str);
char			*apply_space(char *str);
char			*apply_plus(char *str);
char			*apply_field_zero(t_printf *lst, t_flags *lst2, char *str,
		int i);
char			*apply_field_space(t_printf *lst, t_flags *lst2, char *str,
		int i);
char			*apply_precision_str(t_printf *lst, char *str);
char			*apply_precision_num(t_printf *lst, char *str,
		int i);
char			*apply_len_modif(t_printf *lst, char *str, va_list argptr,
		t_flags *lst2);
char			*len_modif_d_i(t_printf *lst, char *str, va_list argptr);
char			*len_modif_o_u(t_printf *lst, char *str, va_list argptr,
		t_flags *lst2);
char			*len_modif_l_z(t_printf *lst, char *str, va_list argptr,
		long long i);
char			*len_modif_h_j(t_printf *lst, char *str, va_list argptr,
		long long i);
char			*len_modif_l_z2(t_printf *lst, char *str, va_list argptr,
		unsigned long long i);
char			*len_modif_h_j2(t_printf *lst, char *str, va_list argptr,
		unsigned long long i);
t_printf		write_char(t_printf *lst, char *str, int i);
t_printf		ft_printf_bis(const char *format, va_list argptr,
		t_printf *lst);
char			*db(long long i, char *str);
char			*db2(unsigned long long i, char *str);
long long		plus(long long i);
char			*ft_unicode(wchar_t c);
t_printf		write_c(t_printf *lst, va_list argptr, t_flags *lst2);
t_printf		percent_analysis(const char *format, t_printf *lsti);
t_printf		apply_percent(t_printf *lst);
t_printf		add_bonus(const char *format, t_printf *lsti);
t_printf		minus_plus(t_printf *lst);
t_printf		write_s(t_printf *lst, va_list argptr, t_flags *lst2);
t_printf		minus_1(t_printf *lst, va_list argptr);
t_printf		minus_0(t_printf *lst, va_list argptr);
char			*precision_minus(char *str, int i2, t_printf *lst, char *c);
t_printf		countdmrd(t_printf *lst, va_list argptr);
t_printf		countdmrd2(t_printf *lst, char *str, va_list argptr);
t_printf		countq(t_printf *lst, wchar_t c);
char			*special(char *str, va_list argptr, t_printf *lst);

#endif
