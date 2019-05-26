/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/24 20:43:50 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		options;
	int			num;

	va_start(options, format);
	while (*format)
	{
		if (*format != '%' && *format && *format != '\n')
			ft_putchar(*format);
		if (*format == '%' && format[1] == '%')
			ft_putchar('%');
		else if (ft_tabs(*format) == 1)
			ft_putchar(*format);
		num = checks(options, format);
		if (*format == '%')
			format += num;
		else
			format++;
	}
	va_end(options);
	return (0);
}
