/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:41:55 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/17 13:39:34 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_strnew(size_t size)
{
	char		*fresh;

	if (!(fresh = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (fresh);
}
