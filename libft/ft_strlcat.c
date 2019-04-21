/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:32:21 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/18 09:29:19 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			lend;
	size_t			lens;
	size_t			o;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	o = 0;
	if (dstsize - ft_strlen(dst) - 1 <= 0)
		return (lend);
	if (!dst || !src)
		return (0);
	if (dstsize < lend)
		return (lens + dstsize);
	while (src[o] && (lend + o + 1) < dstsize)
	{
		dst[lend + o] = src[o];
		o++;
	}
	dst[lend + o] = '\0';
	return (lend + lens);
}
