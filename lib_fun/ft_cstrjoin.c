/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:18:15 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/18 23:43:12 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_cstrjoin(char s1, char *s2)
{
	char		*str;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s2) + 1;
	if (!(str = ft_strnew(len)))
		return (0);
	str[0] = s1;
	ft_strcat(str, s2);
	free(s2);
	return (str);
}
