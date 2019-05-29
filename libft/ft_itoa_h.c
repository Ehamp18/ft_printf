/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:49:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/28 15:29:18 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi_h(short str)
{
	int				sign;
	int				finish;

	sign = 1;
	finish = 0;
	if (str == '-' || str == '+')
	{
		if (str == '-')
			sign = -1;
	}
	while (str >= '0' && str <= '9')
		finish = (finish * 10) + ((int)str++ - '0');
	return (sign * finish);
}
