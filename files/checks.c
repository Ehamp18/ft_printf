/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:23:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/16 20:12:31 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static void				flags_1(const char *format, t_flags *flags)
{
	while (format[flags->check] == '-' || format[flags->check] == '+' ||
		format[flags->check] == '0' || format[flags->check] == ' ' ||
		format[flags->check] == '#')
	{
		if (format[flags->check] == '-')
			INC((flags->minus = 1), flags->check);
		if (format[flags->check] == '+')
			INC((flags->plus = 1), flags->check);
		if (format[flags->check] == '0')
			INC((flags->zero = 1), flags->check);
		if (format[flags->check] == ' ')
			INC((flags->space = 1), flags->check);
		if (format[flags->check] == '#')
			INC((flags->hash = 1), flags->check);
	}
}

static void				fl_2_help(const char *format, t_flags *flags, int cur)
{
	int					j;
	char				*l;

	if (format[flags->check] == '.')
	{
		j = 0;
		l = ft_strnew(ft_strlen(format));
		while (format[flags->check] == '.' && ft_isdigit(format[cur]) == 1)
			INC((l[j] = format[cur++]), j);
		flags->precis = j > 0 ? ft_atoi(l) : -1;
		free(l);
		flags->check += ++j;
	}
	if (format[flags->check] == 'l' || format[flags->check] == 'h')
	{
		if (format[flags->check] == 'l' && format[cur] == 'l')
		{
			INC((flags->length = "ll"), flags->check);
		}
		else if (format[flags->check] == 'h' && format[cur] == 'h')
			flags->check++;
		else if (format[flags->check] == 'l')
			flags->length = "l";
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
			INC((l[j] = format[cur++]), j);
		flags->width = ft_atoi(l);
		free(l);
		flags->check += j;
	}
	cur = flags->check + 1;
	fl_2_help(format, flags, cur);
}

int						checks(va_list options, const char *format, t_val *val)
{
	t_flags				flags;
	int					i;

	i = 0;
	ft_bzero(&flags, sizeof(t_flags));
	flags.check = 1;
	while (*format == '%' && format[flags.check])
	{
		flags_1(format, &flags);
		flags_2(format, &flags);
		if (format[flags.check] == '%')
		{
			con_per(&flags, val);
			break ;
		}
		if (g_conver_check[i].op == format[flags.check])
		{
			g_conver_check[i].kl(options, &flags, val);
			break ;
		}
		i++;
	}
	return (flags.check);
}
