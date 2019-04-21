/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:43:28 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/18 09:31:36 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *hay, const char *need)
{
	int				size;
	int				i;

	size = ft_strlen(need);
	if (!*need)
		return ((char*)hay);
	while (*hay)
	{
		if (*hay != *need)
			hay++;
		else if (*hay == *need)
		{
			i = 0;
			while (hay[i] == need[i])
			{
				i++;
				if (i == size)
					return ((char*)hay);
			}
			hay++;
		}
	}
	return (0);
}
