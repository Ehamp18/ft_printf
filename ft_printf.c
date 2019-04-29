/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/04/28 21:26:18 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
	const char	*form;
	va_list		options;

	form = format;
	va_start(options, format);
	while (*form != '%')
	{
		ft_putchar(*form);
		form++;
	}
	va_arg(options, char); /* Idk where to use this right now */
	va_end(options);
	return (0);
}
