/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:50:48 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/07 01:31:02 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*st;

	st = (unsigned char*)s;
	a = (unsigned char)c;
	while (n)
	{
		if (*st == a)
			return (st);
		++st;
		--n;
	}
	return (0);
}
