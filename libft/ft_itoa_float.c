/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:18:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/28 15:35:01 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int				ft_numcount(double *in)
{
	int					j;

	j = 0;
	while (in[j])
		j++;
	return (j);
}

double					*ft_itoa_float(double flo)
{
	int					len;
	int					test;
	int					i;
	static double		*l = NULL;

	test = flo;
	flo -= test;
	i = 0;
	len = ft_numcount(&flo);
	while (len)
	{
		flo *= 10;
		len--;
	}
	l[i] = test;
	i++;
	l[i] = '.';
	i++;
	l[i] = flo;
	return (l);
}
