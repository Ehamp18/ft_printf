/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/11 19:49:37 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**  Testing
*/
# include <stdio.h>

# define BREAK(x) if (x) break
# define ZERO(x) if (x) return (0)
# define NEG_CHECK(x) if (x < 0) x *= -1
# define NEG_SI_PRNT(x, y) if (x < 0) y = '-'
# define FREE(x, y, z) z = ft_strjoin(x, y); free(x); x = z;
# define ERROR(x) if (x) return (-1)

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			hash;
	int			check;
	int			width;
	int			precis;
	int			sign;
	char		*length;
}				t_flags;

typedef struct	s_count
{
	int			k;
}				t_val;

typedef	void	(*t_charat)(va_list conversions, t_flags *flags, t_val *val);

typedef struct	s_conv_check
{
	char		op;
	t_charat	kl;
}				t_check;


extern t_check	g_conver_check[];

/*
** Converstions
*/

int				ft_printf(const char *format, ...);
void			con_d(va_list options, t_flags *flags, t_val *val);
void			con_i(va_list options, t_flags *flags, t_val *val);
void			con_c(va_list options, t_flags *flags, t_val *val);
void			con_s(va_list options, t_flags *flags, t_val *val);
void			con_x(va_list options, t_flags *flags, t_val *val);
void			con_xa(va_list options, t_flags *flags, t_val *val);
void			con_p(va_list options, t_flags *flags, t_val *val);
void			con_o(va_list options, t_flags *flags, t_val *val);
void			con_u(va_list options, t_flags *flags, t_val *val);
// void			con_f(va_list options, t_flags *flags, t_val *val);
void			con_per(t_flags *flags, t_val *val);
int				checks(va_list options, const char *format, t_val *val);

/*
** Libary_functions
*/

int				ft_atoi(const char *str);
int				ft_is_space(char c);
int				ft_isdigit(int c);
char			*ft_itoa_b(int n);
char			*ft_itoa_base_unsigned(uint64_t n, int base);
char			*ft_itoa_base(int n, int base);
char			*ft_itoa_cx(int64_t n);
// char			*ft_itoa_float(double flo);
int				ft_atoi_h(short str);
int				ft_atoi_hh(char str);
char			*ft_itoa_ll(long long n);
char			*ft_itoa_long(long n);
char			*ft_itoa_o_unsigned(uint64_t n);
char			*ft_itoa_u_p(uint64_t n);
char			*ft_itoa_unsigned(uint64_t n);
char			*ft_itoa_x(int64_t n);
char			*ft_itoa(int64_t n);
void			*ft_memalloc(size_t size);
int				ft_numlen(int num);
void			ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_tabs(char c);
size_t			ft_wordcount(char const *s, char c);

#endif
