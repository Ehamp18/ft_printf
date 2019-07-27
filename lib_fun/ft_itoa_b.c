/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:51:16 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/25 15:10:55 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_b(int n)
{
	const char	index[16] = "0123456789abcdef";
	int			len;
	long		a;
	char		*asc;

	ZERO(!(asc = ft_strnew(ft_numlen(n))));
	asc[0] = '0';
	if (n == 0)
		return (asc);
	a = n;
	len = (n <= 0) ? 1 : 0;
	while (a)
	{
		len++;
		a /= 2;
	}
	a = n;
	CHECK(a < 0, a);
	while (len--)
	{
		asc[len] = index[a % 2];
		a /= 2;
	}
	if (n < 0)
		asc[0] = '-';
	return (asc);
}
