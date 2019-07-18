/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:41:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/16 20:49:28 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

void				*ft_memalloc(size_t size)
{
	void			*fresh;

	if (!(fresh = malloc(size)))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
