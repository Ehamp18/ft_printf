/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:25:21 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/28 15:47:04 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*space_flag(char *a)
{
	char		*s;
	char		*res;

	s = ft_strnew(ft_strlen(a));
	if (a[0] != '-')
	{
		*s = ' ';
		res = ft_strjoin(s, a);
		return (res);
	}
	*s = '-';
	s++;
	res = ft_strjoin(s, a);
	return (res);
}

char			*zero_flag(char *a)
{
	int			i;

	i = ft_strlen(a) - 1;
	while ((ft_isdigit(a[i]) == 1) || (a[i] == '-'))
		i--;
	while ((ft_is_space(a[i]) == 1) && a[i])
	{
		a[i] = '0';
		i--;
	}
	return (a);
}

/*
** '#' : (hash)	Alternate form:
** -- For g and G types, trailing zeros are not removed.
** -- For f, F, e, E, g, G types, the output always contains a decimal point.
** -- For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to
** -- non-zero numbers.
*/



/*
** h
*/

int				h_flag(short k)
{
	int			h;

	h = ft_atoi_h(k);
	return (h);
}

/*
** hh
*/

int				hh_flag(char k)
{
	int			hh;

	hh = ft_atoi_hh(k);
	return (hh);
}

/*
** l
*/

char			*l_flag(long k)
{
	char		*l;

	l = ft_itoa_long(k);
	return (l);
}

/*
** ll
*/

char			*ll_flag(long long k)
{
	char		*ll;

	ll = ft_itoa_ll(k);
	return (ll);
}
