/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_dicsx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:44:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/22 12:44:33 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			con_d(va_list options)
{
	t_flags		flags;
	// t_wiprel	wiprel;
	char		*com;

	com = ft_itoa(va_arg(options, int));
	// if (ft_strcmp(wiprel.length, "l") == 0)
	// 	*com = l_flag(va_arg(options, long));
	// // if (ft_strcmp(wiprel.length, "ll") == 0)
	// // 	*com = l_flag(va_arg(options, long));
	// // if (ft_strcmp(wiprel.length, "h") == 0)
	// // 	*com = l_flag(va_arg(options, long));
	// // if (ft_strcmp(wiprel.length, "hh") == 0)
	// // 	*com = l_flag(va_arg(options, long));
	// // if (wiprel.precis == 1)
	// // 	*com = precision(com);
	// if (wiprel.width == 1)
	// 	*com = width(wiprel.width, com);
	// if (flags.minus == 1)
	// 	*com = minus_flag(com);
	if (flags.plus == 0)
		*com = plus_flag(com);
	// if (flags.zero == 1)
	// 	*com = zero_flag(com);
	// if (flags.space == 1)
	// 	*com = space_flag(com);
	// if (flags.hash == 1)
	// 	*com = hash_flag(com);
	ft_putstr(com);
	free(com);
}

void			con_i(va_list options)
{
	char		*com;

	com = ft_itoa(va_arg(options, int));
	ft_putstr(com);
	free(com);
}

void			con_c(va_list options)
{
	char		com;

	com = (char)va_arg(options, int);
	ft_putchar(com);
}

void			con_s(va_list options)
{
	char		*com;

	com = va_arg(options, char*);
	ft_putstr(com);
}

void			con_x(va_list options)
{
	char		*com;

	com = ft_itoa_x(va_arg(options, int));
	ft_putstr(com);
	free(com);
}
