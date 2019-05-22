/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_poufx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 03:29:47 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/22 04:43:58 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_xa(va_list options)
{
	char		*com;

	com = ft_itoa_cx(va_arg(options, int));
	ft_putstr(com);
	free(com);
}

void			con_p(va_list options)
{
	intptr_t	*a;

	a = (long*)ft_itoa_u_p(va_arg(options, int));
	ft_putstr("0x10");
	ft_putstr((const char*)a);
	free(a);
}

void			con_o(va_list options)
{
	char		*com;

	com = ft_itoa_o_unsigned(va_arg(options, int));
	ft_putstr(com);
	free(com);
}

void			con_u(va_list options)
{
	char		*com;

	com = ft_itoa_unsigned(va_arg(options, int));
	ft_putstr(com);
	free(com);
}

/*
** Need to creat an actual equation for floats.
**
** void			con_f(va_list options)
** {
** 	char		*com;
**
** 	com = ft_itoa_float(va_arg(options, int));
** 	ft_putstr(com);
** 	free(com);
** }
*/
