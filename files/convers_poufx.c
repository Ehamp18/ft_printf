/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_poufx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 03:29:47 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/28 15:36:15 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

void			con_xa(va_list options, t_flags *flags)
{
	char		*com;

	com = ft_itoa_cx(va_arg(options, int));
	if (flags->precis == 1)
		com = precision(flags->precis, com);
	if (flags->width > 0)
		com = width(flags->width, com);
	ft_putstr(com);
	free(com);
}

void			con_p(va_list options, t_flags *flags)
{
	intptr_t	*a;
	char		*com;

	a = (long*)ft_itoa_u_p(va_arg(options, int));
	if (flags->zero == 1)
		com = zero_flag((char*)a);
	ft_putstr("0x10");
	ft_putstr((const char*)a);
	free(a);
}

void			con_o(va_list options, t_flags *flags)
{
	char		*com;

	com = ft_itoa_o_unsigned(va_arg(options, int));
	if (flags->precis == 1)
		com = precision(flags->precis, com);
	if (flags->width > 0)
		com = width(flags->width, com);
	ft_putstr(com);
	free(com);
}

void			con_u(va_list options, t_flags *flags)
{
	char		*com;

	com = ft_itoa_unsigned(va_arg(options, int));
	if (flags->precis == 1)
		com = precision(flags->precis, com);
	if (flags->width > 0)
		com = width(flags->width, com);
	ft_putstr(com);
	free(com);
}

/*
** Need to creat an actual equation for floats.
*/

void			con_f(va_list options, t_flags *flags)
{
	char		*com;

	com = (char*)ft_itoa_float(va_arg(options, int));
	if (flags->plus == 1)
		com = plus_flag(com);
	if (flags->space == 0)
		com = space_flag(com);
	ft_putstr(com);
	free(com);
}
