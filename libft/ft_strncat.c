/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:24:58 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/18 09:28:22 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	int				i;
	int				o;

	o = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[o] != '\0' && (size_t)o < n)
	{
		s1[i + o] = s2[o];
		o++;
	}
	s1[i + o] = '\0';
	return (s1);
}
