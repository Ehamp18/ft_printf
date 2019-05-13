/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:44:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/12 20:47:04 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				con_d(char *d)
{
	int		k;
	char	*i;

	k = (int)*d;
	if (!d)
		return (-1);
	i = ft_itoa(k);
	return (*i);
}
/*
char				con_i(char *i)
{
	if (!i)
		return (-1);
	return (i);
}

char			con_c(char *c)
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

char			con_x(char *x)
{
	if (!x)
		return (-1);
	return (x);
}

char			con_xa(char *X)
{
	if (!X)
		return (-1);
	return (X);
}

char			con_p(char *p)
{
	if (!p || !*p)
		return (0);
	return (p);
}

char			con_o(char *o)
{
	if (!o)
		return (-1);
	return (o);
}

char			con_u(char *u)
{
	if (!u)
		return (-1);
	return (u);
}
*/
