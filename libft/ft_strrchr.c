/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:19:54 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/18 09:30:49 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int				lem;

	lem = ft_strlen(s);
	if (!c)
		return ((char*)s + lem);
	while (lem--)
		if (s[lem] == c)
			return ((char*)s + lem);
	return (0);
}
