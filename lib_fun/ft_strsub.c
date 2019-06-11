/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:03:56 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 18:25:39 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	if (!s)
		return (0);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
