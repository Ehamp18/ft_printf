/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:31:37 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/24 23:30:23 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

int				ft_numlen(int num)
{
	int			len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}
