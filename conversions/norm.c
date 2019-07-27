/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:42:20 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/26 14:07:29 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*per_help(char *point, int perc, t_val *val)
{
	char		*res;
	int			i;

	res = ft_strnew(perc);
	i = ft_strlen(point);
	while (i >= 0)
	{
		if (point[i] == '-')
		{
			val->in = -1;
			point[i] = '0';
		}
		res[perc] = point[i--];
		perc--;
	}
	val->count = perc;
	return (res);
}

char			*min_help(char *s, char *ans, t_flags *flag, t_val *val)
{
	int			i;

	i = 0;
	val->count = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 1 || s[i] == '+')
			ans[val->count++] = s[i];
		else if (s[i] == '-')
		{
			flag->si = '-';
			s[i] = ' ';
			ans[val->count++] = s[i];
		}
		i++;
	}
	return (ans);
}

char			*min_help2(char *s, char *ans, t_flags *flag, t_val *val)
{
	int			i;

	i = ft_strlen(s);
	val->count = 0;
	while (i-- > 0)
	{
		if (ft_isdigit(s[i]) == 1 || s[i] == '+')
			ans[val->wid--] = s[i];
		else if (s[i] == '-')
		{
			flag->si = '-';
			s[i] = ' ';
			ans[val->count++] = s[i];
		}
	}
	return (ans);
}
