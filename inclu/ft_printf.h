/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/17 19:36:40 by elhampto         ###   ########.fr       */
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
# include <wctype.h>

# define BREAK(x) if (x) break
# define ZERO(x) if (x) return (0)
# define NEG_CHECK(x) if (x < 0) x *= -1
# define NEG_SI_PRNT(x, y) if (x < 0) y = '-'
# define FREE(x, y, z) z = ft_strjoin(x, y); free(x); x = z;
# define FE(x, y) x = y; free(y)
# define CPY(x, y) y = ft_strcat(y, x); free(x)
# define ERROR(x) if (x) return (-1)
# define CHECK(x, y) if (x) y *= -1
# define RETZE(x) if (x) return ("0")
# define RETY(x, y) if (x) return (y)
# define INC(x, y) if (x) y++
# define DEC(x, y) if (x) y--

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
	char		si;
	char		*length;
}				t_flags;

typedef struct	s_count
{
	int			k;
	int			in;
	int			count;
	int			zero;
	int			wid;
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
void			con_b(va_list options, t_flags *flags, t_val *val);
int				con_per(t_flags *flags, t_val *val);
int				checks(va_list options, const char *format, t_val *val);
char			*plus_help(t_flags *flag, char *a, char *s, t_val *val);
char			*per_help(char *point, int perc, t_val *val);
char			*min_help(char *s, char *ans, t_flags *flag, t_val *val);
char			*min_help2(char *s, char *ans, t_flags *flag, t_val *val);

/*
** Libary_functions
*/

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_cstrjoin(char s1, char *s2);
char			*ft_ccstrjoin(char s1, char s2, char *s3);
int				ft_is_space(char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isint(int c);
char			*ft_itoa_b(int n);
char			*ft_itoa_base_unsigned(uint64_t n, int base);
char			*ft_itoa_base(int n, int base);
char			*ft_itoa_cx(uint64_t n);
int				ft_atoi_h(short str);
int				ft_atoi_hh(char str);
char			*ft_itoa_ll(long long n);
char			*ft_itoa_long(long n);
char			*ft_itoa_o_unsigned(uint64_t n);
char			*ft_itoa_u_p(intptr_t n);
char			*ft_itoa_unsigned(uint64_t n);
char			*ft_itoa_x(uint64_t n);
char			*ft_itoa(int64_t n);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
int				ft_numlen(int num);
int				ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strrev_cpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_tabs(char c);
size_t			ft_wordcount(char const *s, char c);

#endif
