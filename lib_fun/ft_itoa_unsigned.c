/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:37:02 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/03 22:44:31 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_unsigned(uint64_t n)
{
	const char	index[10] = "0123456789";
	int			len;
	uint64_t	a;
	char		*asc;

	a = n;
	len = 0;
	while (a)
	{
		len++;
		a /= 10;
	}
	a = n;
	if (!(asc = ft_strnew(len)))
		return (0);
	while (len--)
	{
		asc[len] = index[a % 10];
		a /= 10;
	}
	return (asc);
}
