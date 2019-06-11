/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:13 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 12:06:46 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_i(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc < i)
		return (point);
	if (!perc)
		perc = 0;
	perc -= i;
	while (i >= 0 && perc)
	{
		res[i] = point[i];
		i--;
	}
	while (perc >= 0)
	{
		res[perc] = '0';
		perc--;
	}
	return (res);
}

static char			*width_i(int wid, char *s)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	i = ft_strlen(s);
	if (wid < i)
		return (s);
	// wid -= i;
	while (i >= 0)
	{
		ans[i] = s[i];
		i--;
	}
	while ((wid > 0))
	{
		ans[wid] = (' ');
		wid--;
	}
	return (ans);
}

static char			*space_flag_i(char *a)
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
	return (res);
}

static char			*zero_flag_i(char *a)
{
	int				i;

	i = ft_strlen(a) - 1;
	while ((ft_isdigit(a[i]) == 1) || (a[i] == '-'))
		i--;
	while ((ft_is_space(a[i]) == 1) && a[i])
	{
		a[i] = '0';
		i--;
	}
	return (a);
}

static char			*plus_flag_i(char *a, int i)
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
	if (*a == '+')
		a++;
	*s = '+';
	res = ft_strjoin(s, a);
	return (res);
}

static char			*minus_flag_i(char *m)
{
	int				j;
	int				i;
	char			*res;

	j = 0;
	i = 0;
	res = ft_strnew(ft_strlen(m));
	while (ft_is_space(*m) == 1)
	{
		j++;
		m++;
	}
	while (*m)
	{
		res[i] = *m;
		m++;
		i++;
	}
	if (*m == 0)
	{
		m++;
		j++;
	}
	while (j > 0)
	{
		res[i] = ' ';
		j--;
		i++;
	}
	return (res);
}

void				con_i(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, int64_t);
	else
		a = va_arg(options, int32_t);
	com = ft_itoa(a);
	if (*com == '-' && flags->minus == 1)
	{
		flags->sign = 1;
		val->k++;
		com++;
	}
	if (flags->precis > 0)
		com = precision_i(flags->precis, com);
	if (flags->width > 0)
		com = width_i(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_i(com);
	if (flags->space == 1)
		com = space_flag_i(com);
	if (flags->minus == 1)
		com = minus_flag_i(com);
	if (flags->plus == 1)
		com = plus_flag_i(com, flags->sign);
	val->k += ft_putstr(com);
}
