/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:23:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/03 13:08:18 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static void				flags_1(const char *format, t_flags *flags)
{
	if (format[flags->check] == '-')
	{
		flags->minus = 1;
		flags->check++;
	}
	if (format[flags->check] == '+')
	{
		flags->plus = 1;
		flags->check++;
	}
	if (format[flags->check] == '0')
	{
		flags->zero = 1;
		flags->check++;
	}
	if (format[flags->check] == ' ')
	{
		flags->space = 1;
		flags->check++;
	}
	if (format[flags->check] == '#')
	{
		flags->hash = 1;
		flags->check++;
	}
}

static void				flags_2(const char *format, t_flags *flags)
{
	int					point;
	char				*l;
	int					j;

	point = flags->check;
	if (ft_isdigit(format[flags->check]) == 1)
	{
		j = 0;
		l = (char*)ft_memalloc(ft_strlen(format) + 1);
		while (ft_isdigit(format[point]) == 1)
		{
			l[j] = format[point];
			j++;
			point++;
		}
		flags->width = ft_atoi(l);
		free(l);
		flags->check += j;
	}
	point = flags->check + 1;
	if (format[flags->check] == '.' && ft_isdigit(format[point]) == 1)
	{
		j = 0;
		l = (char*)ft_memalloc(ft_strlen(format) + 1);
		while (format[flags->check] == '.' && ft_isdigit(format[point]) == 1)
		{
			l[j] = format[point++];
			j++;
		}
		flags->precis = ft_atoi(l);
		free(l);
		flags->check += ++j;
	}
	if (format[flags->check] == 'l' || format[flags->check] == 'h')
	{
		if (format[flags->check] == 'l' && format[point] == 'l')
			flags->length = "ll";
		else if (format[flags->check] == 'h' && format[point] == 'h')
			flags->length = "hh";
		else if (format[flags->check] == 'l')
			flags->length = "l";
		else if (format[flags->check] == 'h')
			flags->length = "h";
		(ft_strlen(flags->length) >= 2) ? flags->check + 2 : flags->check++;
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
		flags_2(format, flags);
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
