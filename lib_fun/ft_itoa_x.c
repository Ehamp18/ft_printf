/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:40:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/01 22:18:23 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_itoa_x(uint64_t n)
{
	const char	index[16] = "0123456789abcdef";
	int			len;
	uint64_t	a;
	char		*asc;

	if (n == 0)
		return ("0");
	a = n;
	len = 0;
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
