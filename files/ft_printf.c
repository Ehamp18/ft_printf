/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/09 23:12:28 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		options;
	int			num;
	t_val		*val;

	va_start(options, format);
	val = (t_val*)ft_memalloc(sizeof(t_val));
	val->k = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			val->k++;
		}
		else
			num = checks(options, format, val);
		if (*format == '%')
			format += num;
		format++;
	}
	va_end(options);
	return (val->k);
}
