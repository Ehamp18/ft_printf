/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 03:20:59 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/27 14:32:05 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				ft_atoc(unsigned int asc)
{
	if (!asc)
		return (0);
	if (asc >= 32 && asc <= 126)
		return (asc);
	while (!(asc >= 32 && asc <= 126))
	{
		if (asc < 32)
			asc = asc + 32;
		else if (asc > 126)
			asc = asc - 126;
	}
	return (asc);
}
