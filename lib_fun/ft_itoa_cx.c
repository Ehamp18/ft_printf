/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:40:48 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/03 21:07:03 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_cx(int n)
{
	const char	index[16] = "0123456789ABCDEF";
	int			len;
	long		a;
	char		*asc;

	a = n;
	len = (n <= 0) ? 1 : 0;
	while (a)
	{
		len++;
		a /= 16;
	}
	a = n;
	if (a < 0)
		a *= -1;
	if (!(asc = ft_strnew(len)))
		return (0);
	while (len--)
	{
		asc[len] = index[a % 16];
		a /= 16;
	}
	if (n < 0)
		asc[0] = '-';
	return (asc);
}
