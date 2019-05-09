/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:52:49 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/09 10:40:11 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include "libft/libft.h"
# include <stdarg.h>

typedef	void(*charat)(char *conversions);

typedef struct	conv_check
{
	char		op;
	charat		kl;
}				check;

int				ft_printf(const char *format, ...);
char			con_d(int d);
char			con_i(int i);
char			con_c(char c);
char			con_s(char *s);
char			con_x(int x);
char			con_X(int X);
char			*con_p(char *p);
char			con_o(unsigned int o);
char			con_u(unsigned int u);

#endif
