/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:18:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/21 20:43:55 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>

static int			ft_numcount(double *in)
{
	int			j;

	j = 0;
	while (in[j])
		j++;
	return (j);
}

double				ft_itoa_asd(double flo)
{
	int			len;
	int			test;
	int			i;
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
	// flo += test;
	return (*l);
}

int			main(void)
{
	double a;

	a = 125.368;
	printf("check 1: %f\n", a);
	a = ft_itoa_asd(a);
	printf("check 2: %f\n", a);
	return (0);
}

/*
** char				*ft_itoa_float(int n)
** {
** 	const char	index[10] = "0123456789";
** 	int			len;
** 	long		a;
** 	char		*asc;
**
** 	a = n;
** 	len = (n <= 0) ? 1 : 0;
** 	while (a)
** 	{
** 		len++;
** 		a /= 10;
** 	}
** 	a = n;
** 	NEG_CHECK(a);
** 	ZERO(!(asc = ft_strnew(len)));
** 	while (len--)
** 	{
** 		asc[len] = index[a % 10];
** 		a /= 10;
** 	}
** 	NEG_SI_PRNT(n, asc[0]);
** 	return (asc);
** }
*/
