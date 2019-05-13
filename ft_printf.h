/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/12 20:48:45 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include "libft/libft.h"
# include <stdarg.h>

typedef	char	(*t_charat)(char *conversions);

typedef struct	s_conv_check
{
	char		op;
	t_charat	kl;
}				t_check;

extern t_check	g_conver_check[];

int				ft_printf(const char *format, ...);
char			con_d(char *d);
char			con_i(char *i);
char			con_c(char *c);
char			con_s(char *s);
char			con_x(char *x);
char			con_xa(char *X);
char			con_p(char *p);
char			con_o(char *o);
char			con_u(char *u);

#endif
