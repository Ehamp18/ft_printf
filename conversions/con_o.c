/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 16:16:38 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static int			h_flag_o(short k)
{
	int				h;

	h = ft_atoi_h(k);
	return (h);
}

static int			hh_flag_o(char k)
{
	int				hh;

	hh = ft_atoi_hh(k);
	return (hh);
}

static char			*l_flag_o(long k)
{
	char			*l;

	l = ft_itoa_long(k);
	return (l);
}

static char			*ll_flag_o(long long k)
{
	char			*ll;

	ll = ft_itoa_ll(k);
	return (ll);
}

static char			*precision_o(int perc, char *point)
{
	int				i;
	char			*res;
	int				j;

	res = ft_strnew(ft_numlen(perc));
	j = ft_numlen(perc);
	i = ft_strlen(point);
	if (!perc)
		return (point);
	if (perc < (int)ft_strlen(point))
		return (point);
	perc -= i;
	while (i >= 0)
	{
		res[j] = point[i];
		i--;
		j--;
	}
	while ((perc > 0))
	{
		res[j] = ('0');
		perc--;
		j--;
	}
	return (res);
}

static char			*width_o(int wid, char *s)
{
	int				i;
	char			*ans;
	int				j;

	ans = ft_strnew(ft_numlen(wid));
	j = ft_numlen(wid);
	i = ft_strlen(s);
	if (!wid)
		return (s);
	if (wid < i)
		return (s);
	wid -= i;
	while (i >= 0)
	{
		ans[j] = s[i];
		i--;
		j--;
	}
	while ((wid > 0))
	{
		ans[j] = (' ');
		wid--;
		j--;
	}
	return (ans);
}

static char			*zero_flag_o(char *a)
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

static char			*minus_flag_o(char *m)
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
	while (j)
	{
		res[i] = ' ';
		j--;
		i++;
	}
	return (res);
}

void				con_o(va_list options, t_flags *flags, t_val *val)
{
	char			*com;

	com = (char*)ft_memalloc(sizeof(flags));
	if (flags->length)
	{
		if (ft_strcmp(flags->length, "l") == 0)
			com = l_flag_o(va_arg(options, long));
		if (ft_strcmp(flags->length, "ll") == 0)
			com = ll_flag_o(va_arg(options, long long));
		if (ft_strcmp(flags->length, "h") == 0)
			*com = (short)h_flag_o(va_arg(options, int));
		if (ft_strcmp(flags->length, "hh") == 0)
			*com = (char)hh_flag_o(va_arg(options, int));
	}
	if (!flags->length)
		com = ft_itoa_o_unsigned(va_arg(options, int));
	if (*com == '-')
	{
		flags->sign = 1;
		com++;
	}
	if (flags->precis > 0)
		com = precision_o(flags->precis, com);
	if (flags->width > 0)
		com = width_o(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_o(com);
	if (flags->minus == 1)
		com = minus_flag_o(com);
	val->k += ft_putstr(com);
}
