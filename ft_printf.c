/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/12 20:54:48 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check to make sure a string was inputted
** -- If input was not found, return error message
**
** Check to see if there is any text before
** --if there is then print it out
**
** Check for a sign with a given number
**
** Check for the data type being clalled
** --Then dependig on the case go accordinly
**
** Declare the function and the values it will require
** -- Have the case so that the correct function type can be called and used
*/

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		options;

	i = 0;
	va_start(options, format);
	while (*format != '%' && *format)
		ft_putchar(*format++);
	while (*format && format[i])
	{
		if (*format == '%' && format[1] == '%')
			ft_putchar('%');
		else if (ft_is_space(*format) == 1)
			ft_putchar(*format);
		else if (*format == '%' && ft_isalpha(format[1]) == 1)
			g_conver_check[i]->(va_arg(options, char*));
		else if (format[i] == '\n')
			ft_putchar('\n');
		format++;
	}
	va_end(options);
	ft_putchar('\n');
	return (0);
}
