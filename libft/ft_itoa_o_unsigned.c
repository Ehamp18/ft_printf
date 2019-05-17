/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_o_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:38:52 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/16 19:39:36 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_o_unsigned(uint64_t n)
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
		a /= 8;
	}
	a = n;
	if (!(asc = ft_strnew(len)))
		return (0);
	while (len--)
	{
		asc[len] = index[a % 8];
		a /= 8;
	}
	return (asc);
}
