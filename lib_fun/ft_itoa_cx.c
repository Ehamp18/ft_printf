/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:40:48 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/01 00:49:02 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_cx(uint64_t n)
{
	const char	index[16] = "0123456789ABCDEF";
	int			len;
	uint64_t	a;
	char		*asc;

	ZERO(!(asc = ft_strnew(ft_unumlen(n))));
	asc[0] = '0';
	if (n == 0)
		return (asc);
	a = n;
	len = 0;
	while (a)
	{
		len++;
		a /= 16;
	}
	a = n;
	while (len--)
	{
		asc[len] = index[a % 16];
		a /= 16;
	}
	return (asc);
}
