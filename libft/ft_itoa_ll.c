/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:47:20 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/28 14:48:21 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_ll(long long n)
{
	const char		index[10] = "0123456789";
	long long		len;
	long long		a;
	char			*asc;

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
