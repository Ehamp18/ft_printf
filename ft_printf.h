/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/16 19:55:16 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include "libft/libft.h"
# include <stdarg.h>

# define BREAK(x) if (x) break
# define ZERO(x) if (x) return (0)

typedef	void	(*t_charat)(va_list *conversions);

typedef struct	s_conv_check
{
	char		op;
	t_charat	kl;
}				t_check;

extern t_check	g_conver_check[];

int				ft_printf(const char *format, ...);
void			con_d(va_list *options);
void			con_i(va_list *options);
void			con_c(va_list *options);
void			con_s(va_list *options);
void			con_x(va_list *options);
void			con_xa(va_list *options);
void			con_p(va_list *options);
void			con_o(va_list *options);
void			con_u(va_list *options);

#endif
