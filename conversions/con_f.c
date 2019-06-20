/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:05 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/19 23:41:40 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*space_flag_f(char *a)
{
	char			*s;
	char			*res;

	s = ft_strnew(ft_strlen(a));
	if (a[0] != '-')
	{
		*s = ' ';
		res = ft_strjoin(s, a);
		return (res);
	}
	*s = '-';
	s++;
	res = ft_strjoin(s, a);
	free(s);
	return (res);
}

static char			*plus_flag_f(char *a, int i)
{
	char			*s;
	char			*res;
	int				j;

	j = 0;
	s = ft_strnew(ft_strlen(a));
	while (ft_isdigit(*a) == 0)
	{
		if (a[j] == '-')
		{
			a++;
			*s = '-';
			res = ft_strjoin(s, a);
			return (res);
		}
		a++;
	}
	if (i == 1)
	{
		a++;
		*s = '-';
		res = ft_strjoin(s, a);
		return (res);
	}
	a++;
	*s = '+';
	res = ft_strjoin(s, a);
	return (res);
}

void				con_f(va_list options, t_flags *flags, t_val *val)
{
	double			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, int64_t);
	else
		a = va_arg(options, int32_t);
	com = ft_itoa_float(a);
	if (*com == '-')
	{
		flags->sign = 1;
		com++;
	}
	if (flags->width > 0)
		com = width_f(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_f(com);
	if (flags->space == 1)
		com = space_flag_f(com);
	if (flags->plus == 1)
		com = plus_flag_f(com, flags->sign);
	if (flags->minus == 1)
		com = minus_flag_f(com);
	val->k += ft_putstr(com);
}
