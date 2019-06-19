/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:40:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/17 10:04:29 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_u_p(intptr_t n)
{
	const char	index[16] = "0123456789abcdef";
	int			len;
	intptr_t	a;
	char		*asc;

	a = n;
	len = (n <= 0) ? 1 : 0;
	while (a)
	{
		len++;
		a /= 16;
	}
	a = n;
	if (!(asc = ft_strnew(len)))
		return (0);
	while (len--)
	{
		asc[len] = index[a % 16];
		a /= 16;
	}
	return (asc);
}
