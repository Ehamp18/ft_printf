/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags->checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 23:37:28 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/23 17:30:28 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			flags_1(const char *format, t_flags *flags)
{
	if (format[flags->check] == '-')
	{
		flags->minus = 1;
		flags->check++;
	}
	else if (format[flags->check] == '+')
	{
		flags->plus = 1;
		flags->check++;
	}
	else if (format[flags->check] == '0')
	{
		flags->zero = 1;
		flags->check++;
	}
	else if (format[flags->check] == ' ')
	{
		flags->space = 1;
		flags->check++;
	}
	else if (format[flags->check] == '#')
	{
		flags->hash = 1;
		flags->check++;
	}
}

static void			flags_2(const char *format, t_flags *flags)
{
	int					point;

	point = flags->check + 1;
	if (ft_isdigit(format[flags->check]) == 1)
	{
		flags->width = ft_atoi(&format[flags->check]);
		flags->check++;
	}
	if (format[flags->check] == '.' && ft_isdigit(format[point]) == 1)
	{
		flags->precis = 1;
		flags->prec_num = ft_atoi(&format[flags->check]);
		flags->check += ft_numlen(ft_atoi(&format[flags->check]));
	}
	if (format[flags->check] == 'l' || format[flags->check] == 'h')
	{
		if (format[flags->check] == 'l' && format[point] == 'l')
		{
			flags->length = "ll";
			flags->check++;
		}
		else if (format[flags->check] == 'h' && format[point] == 'h')
		{
			flags->length = "hh";
			flags->check++;
		}
		else if (format[flags->check] == 'l')
			flags->length = "l";
		else if (format[flags->check] == 'h')
			flags->length = "h";
		flags->check++;
	}
}

int						checks(va_list options, const char *format)
{
	t_flags				*flags;
	int					i;

	i = -1;
	flags = (t_flags*)ft_memalloc(sizeof(t_flags));
	flags->check = 1;
	while (*format == '%' && format[flags->check])
	{
		flags_1(format, flags);
		flags_2(format,flags);
		if (g_conver_check[++i].op == format[flags->check])
		{
			g_conver_check[i].kl(options, flags);
			i = -1;
			break ;
		}
	}
	flags->check++;
	return (flags->check);
}
