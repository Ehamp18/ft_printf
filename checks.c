/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 23:37:28 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/22 12:21:09 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				flags(const char *format, int check)
{
	t_flags				*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	if (format[check] == '-')
	{
		flags->minus = 1;
		check++;
	}
	else if (format[check] == '+')
	{
		flags->plus = 1;
		check++;
	}
	else if (format[check] == '0')
	{
		flags->zero = 1;
		check++;
	}
	else if (format[check] == ' ')
	{
		flags->space = 1;
		check++;
	}
	else if (format[check] == '#')
	{
		flags->hash = 1;
		check++;
	}
	free(flags);
	return (check);
}

static int				flags_2(const char *format, int check)
{
	t_wiprel			*confer;

	confer = (t_wiprel*)malloc(sizeof(t_wiprel));
	if (ft_isdigit(format[check]) == 1)
	{
		confer->width = format[check];
		check++;
	}
	if (format[check] == '.' && ft_isdigit(format[check]) == 1)
	{
		confer->precis = 1;
		check++;
	}
	if (format[check] == 'l' || format[check] == 'h')
	{
		if (format[check] == 'l' && format[check + 1] == 'l')
			confer->length = "ll";
		else if (format[check] == 'h' && format[check + 1] == 'h')
			confer->length = "hh";
		else if (format[check] == 'l')
			confer->length = "l";
		else if (format[check] == 'h')
			confer->length = "h";
		check++;
	}
	free(confer);
	return (check);
}

int					checks(va_list options, const char *format)
{
	int					check;
	int					i;

	i = -1;
	check = 1;
	while (*format == '%' && format[check])
	{
		check = flags(format, check);
		check = flags_2(format, check);
		if (g_conver_check[++i].op == format[check])
		{
			g_conver_check[i].kl(options);
			i = -1;
			break ;
		}
	}
	check++;
	return (check);
}
