/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:44:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/14 16:26:46 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

int					ft_atoi(const char *str)
{
	int				finish;
	int				sign;

	sign = 1;
	finish = 0;
	while (*str == '\r' || *str == '\f' || *str == '\v' ||
		*str == '\t' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		finish = (finish * 10) + ((int)*str++ - '0');
	return (sign * finish);
}
