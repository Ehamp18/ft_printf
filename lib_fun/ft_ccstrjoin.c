/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccstrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:33:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/25 16:38:31 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_ccstrjoin(char s1, char s2, char *s3)
{
	char		*str;
	size_t		len;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len = ft_strlen(s3) + 2;
	if (!(str = ft_strnew(len)))
		return (0);
	str[0] = s1;
	str[1] = s2;
	ft_strcat(str, s3);
	return (str);
}
