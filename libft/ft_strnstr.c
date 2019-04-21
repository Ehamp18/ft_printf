/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:20:03 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/18 09:32:21 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *hay, const char *need, size_t len)
{
	int				size;
	int				i;

	if (!*need)
		return ((char*)hay);
	size = ft_strlen(need);
	while (*hay && len)
	{
		i = 0;
		while (*hay && hay[i] == need[i] && len - i)
		{
			if (i + 1 == size)
				return ((char*)hay);
			i++;
		}
		hay++;
		len--;
	}
	return (0);
}
