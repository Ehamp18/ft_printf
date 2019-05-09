/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:44:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/09 10:40:10 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				con_d(int d)
{
	if (!d)
		return (-1);
	ft_itoa(d);
	return (d);
}

char				con_i(int i)
{
	if (!i)
		return (-1);
	return (i);
}

char			con_c(char c)
{
	if (!c)
		return (-1);
	return (c);
}

char			con_s(char *s)
{
	if (!s || !*s)
		return (-1);
	return (*s);
}

char			con_x(int x)
{
	if (!x)
		return (-1);
	return (x);
}

char			con_X(int X)
{
	if (!X)
		return (-1);
	return (X);
}

char			*con_p(char *p)
{
	if (!p || !*p)
		return NULL;
	return (p);
}

char			con_o(unsigned int o)
{
	if (!o)
		return (-1);
	return (o);
}

char			con_u(unsigned int u)
{
	if (!u)
		return (-1);
	return (u);
}
