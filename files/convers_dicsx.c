/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_dicsx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:44:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/03 15:02:03 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

void			con_d(va_list options, t_flags *flags)
{
	char		*com;

	if (flags->length)
	{
		if (ft_strcmp(flags->length, "l") == 0)
			com = l_flag(va_arg(options, long));
		if (ft_strcmp(flags->length, "ll") == 0)
			com = l_flag(va_arg(options, long));
		if (ft_strcmp(flags->length, "h") == 0)
			com = l_flag(va_arg(options, long));
		if (ft_strcmp(flags->length, "hh") == 0)
			com = l_flag(va_arg(options, long));
	}
	if (!flags->length)
		com = ft_itoa(va_arg(options, int));
	if (*com == '-')
	{
		flags->sign = 1;
		com++;
	}
	if (flags->precis > 0)
		com = precision(flags->precis, com);
	if (flags->width > 0)
		com = width(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag(com);
	if (flags->space == 1)
		com = space_flag(com);
	if (flags->plus == 1)
		com = plus_flag(com, flags->sign);
	if (flags->minus == 1)
		com = minus_flag(com);
	ft_putstr(com);
	free(com);
}

void			con_i(va_list options, t_flags *flags)
{
	char		*com;

	com = ft_itoa(va_arg(options, int));
	if (flags->precis == 1)
		com = precision(flags->precis, com);
	if (flags->width > 0)
		com = width(flags->width, com);
	if (flags->plus == 1)
		com = plus_flag(com, flags->sign);
	if (flags->space == 1)
		com = space_flag(com);
	ft_putstr(com);
	free(com);
}

void			con_c(va_list options, t_flags *flags)
{
	char		com;

	com = (char)va_arg(options, int);
	if (flags->zero == 1)
		com = *zero_flag(&com);
	ft_putchar(com);
}

void			con_s(va_list options, t_flags *flags)
{
	char		*com;

	com = va_arg(options, char*);
	if (flags->zero == 1)
		com = zero_flag(com);
	ft_putstr(com);
}

void			con_x(va_list options, t_flags *flags)
{
	char		*com;

	com = ft_itoa_x(va_arg(options, int));
	if (flags->precis == 1)
		com = precision(flags->precis, com);
	if (flags->width > 0)
		com = width(flags->width, com);
	ft_putstr(com);
	free(com);
}
