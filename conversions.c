/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:44:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/02 21:16:59 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				con_d(int d)
{
	if (!d)
		return (-1);
	ft_itoa(d);
	return (d);
}

// int				con_i(int i)
// {}

// char			con_c(char c)
// {}

// char			con_s(char *s)
// {}

// int				con_x(int x)
// {}

// int				con_X(int X)
// {}

// void			*con_p(char *p)
// {}

// int				con_o(unsigned )
// {}

// int				con_u(unsigned int u)
// {}
