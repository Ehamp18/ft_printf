/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:51:16 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/08 20:47:46 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_b(int n)
{
	const char	index[16] = "0123456789abcdef";
	int			len;
	long		a;
	char		*asc;

	RETZE(n == 0);
	a = n;
	len = (n <= 0) ? 1 : 0;
	while (a)
	{
		len++;
		a /= 2;
	}
	a = n;
	CHECK(a < 0, a);
	if (!(asc = ft_strnew(len)))
		return (0);
	while (len--)
	{
		asc[len] = index[a % 2];
		a /= 2;
	}
	if (n < 0)
		asc[0] = '-';
	return (asc);
}
