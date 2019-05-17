/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:44:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/16 20:10:50 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_d(va_list *options)
{
	char		*com;

	com = ft_itoa(va_arg(*options, int));
	ft_putstr(com);
	free(com);
}

void			con_i(va_list *options)
{
	char		*com;

	com = ft_itoa(va_arg(*options, int));
	ft_putstr(com);
	free(com);
}

void			con_c(va_list *options)
{
	char		com;

	com = (char)va_arg(*options, int);
	ft_putchar(com);
}

void			con_s(va_list *options)
{
	char		*com;

	com = va_arg(*options, char*);
	ft_putstr(com);
}

void			con_x(va_list *options)
{
	char		*com;

	com = ft_itoa_x(va_arg(*options, int));
	ft_putstr(com);
	free(com);
}

void			con_xa(va_list *options)
{
	char		*com;

	com = ft_itoa_cx(va_arg(*options, int));
	ft_putstr(com);
	free(com);
}

void			con_p(va_list *options)
{
	intptr_t	*a;

	a = (long*)ft_itoa_u_p(va_arg(*options, int));
	ft_putstr("0x10");
	ft_putstr((const char*)a);
	free(a);
}

void			con_o(va_list *options)
{
	char		*com;

	com = ft_itoa_o_unsigned(va_arg(*options, int));
	ft_putstr(com);
	free(com);
}

void			con_u(va_list *options)
{
	char		*com;

	com = ft_itoa_unsigned(va_arg(*options, int));
	ft_putstr(com);
	free(com);
}
