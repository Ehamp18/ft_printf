/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:37:14 by elhampto          #+#    #+#             */
/*   Updated: 2019/04/18 18:57:21 by elhampto         ###   ########.fr       */
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

int			printf(const char *format, ...)
{
	char	type{'d', 's', 'c', 'li', 'p', 'i', 'o', 'u', 'x', 'X'};
	int		i;
	int		h;

	i = 0;
	h = 0;
	while (format[i] != '%')
	{
		ft_putchar(format[i]);
		i++;
	}
	/*
	** If ther is a % then check next char
	** -- If the char is a %%
	** -- if the char is a char then check for the corresponding matching formula
	*/
	/*
	** Parse the input
	*/
	return (0);
}
