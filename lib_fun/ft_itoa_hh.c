/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:51:18 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/03 22:48:21 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

int				ft_atoi_hh(char str)
{
	int			sign;
	int			finish;

	sign = 1;
	finish = 0;
	if (str == '-' || str == '+')
	{
		if (str == '-')
			sign = -1;
	}
	while (str >= '0' && str <= '9')
		finish = (finish * 10) + (str - '0');
	return (sign * finish);
}
