/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:17:07 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/03 22:44:56 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa(int n)
{
	const char	index[10] = "0123456789";
	int			len;
	long		a;
	char		*asc;

	a = n;
	len = (n <= 0) ? 1 : 0;
	while (a)
	{
		len++;
		a /= 10;
	}
	a = n;
	NEG_CHECK(a);
	ZERO(!(asc = ft_strnew(len)));
	while (len--)
	{
		asc[len] = index[a % 10];
		a /= 10;
	}
	NEG_SI_PRNT(n, asc[0]);
	return (asc);
}
