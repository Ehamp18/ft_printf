/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:25:31 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 18:24:25 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

size_t			ft_wordcount(char const *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}
