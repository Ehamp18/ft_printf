/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/16 17:39:13 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		options;

	i = 0;
	va_start(options, format);
	while (*format)
	{
		if (*format != '%' && *format && *format != '\n')
			ft_putchar(*format);
		if (*format == '%' && format[1] == '%')
			ft_putchar('%');
		else if (*format == '\r' || *format == '\f' || *format == '\v' ||
		*format == '\t' || *format == '\n')
			ft_putchar(*format);
		while (*format == '%' && ft_isalpha(format[1]) == 1)
		{
			if (g_conver_check[i].op == format[1])
			{
				g_conver_check[i].kl(&options);
				i = 0;
				format++;
				break ;
			}
			i++;
		}
		format++;
	}
	va_end(options);
	return (0);
}
