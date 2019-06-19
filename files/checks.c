/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:23:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/17 20:49:22 by elhampto         ###   ########.fr       */
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
	int					cur;
	char				*l;
	int					j;

	cur = flags->check;
	if (ft_isdigit(format[flags->check]) == 1)
	{
		j = 0;
		l = ft_strnew(ft_strlen(format));
		while (ft_isdigit(format[cur]) == 1)
		{
			l[j] = format[cur++];
			j++;
		}
		flags->width = ft_atoi(l);
		free(l);
		flags->check += j;
	}
	cur = flags->check + 1;
	if (format[flags->check] == '.')
	{
		j = 0;
		l = ft_strnew(ft_strlen(format));
		while (format[flags->check] == '.' && ft_isdigit(format[cur]) == 1)
		{
			l[j] = format[cur++];
			j++;
		}
		if (j > 0)
			flags->precis = ft_atoi(l);
		else if ((format[flags->check] == '.' && format[cur] == 0) ||
			format[flags->check] == '.')
			flags->precis = -1;
		free(l);
		flags->check += ++j;
	}
	if (format[flags->check] == 'l' || format[flags->check] == 'h')
	{
		if (format[flags->check] == 'l' && format[cur] == 'l')
		{
			flags->length = "ll";
			flags->check++;
		}
		else if (format[flags->check] == 'h' && format[cur] == 'h')
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

int						checks(va_list options, const char *format, t_val *val)
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
		if (format[flags->check] == '%')
		{
			con_per(flags, val);
			break ;
		}
		if (g_conver_check[++i].op == format[flags->check])
		{
			g_conver_check[i].kl(options, flags, val);
			i = -1;
			break ;
		}
	}
	return (flags->check);
}
