/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:33:10 by rsmith            #+#    #+#             */
/*   Updated: 2019/07/12 14:44:31 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_strdup(char *src)
{
	char *dup;

	if (!src)
		return (NULL);
	dup = (char*)malloc(sizeof(*dup) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, src);
	return (dup);
}
