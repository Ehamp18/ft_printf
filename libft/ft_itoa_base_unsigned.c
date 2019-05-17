/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:47:42 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/16 18:53:08 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base_unsigned(uint64_t n, int base)
{
	const char	index[16] = "0123456789abcdef";
	int			len;
	uint64_t	a;
	char		*asc;

	a = n;
	len = 0;
	while (a)
	{
		len++;
		a /= base;
	}
	a = n;
	if (!(asc = ft_strnew(len)))
		return (0);
	while (len--)
	{
		asc[len] = index[a % base];
		a /= base;
	}
	return (asc);
}
