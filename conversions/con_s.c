/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 00:52:58 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static int			h_flag_s(short k)
{
	int				h;

	h = ft_atoi_h(k);
	return (h);
}

static int			hh_flag_s(char k)
{
	int				hh;

	hh = ft_atoi_hh(k);
	return (hh);
}

static char			*l_flag_s(long k)
{
	char			*l;

	l = ft_itoa_long(k);
	return (l);
}

static char			*ll_flag_s(long long k)
{
	char			*ll;

	ll = ft_itoa_ll(k);
	return (ll);
}

static char			*precision_s(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(ft_numlen(perc));
	i = 0;
	if (!perc)
		return (res);
	while (i >= 0 && perc > 0)
	{
		res[i] = point[i];
		i++;
		perc--;
	}
	return (res);
}

static char			*width_s(int wid, char *s)
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

static char			*zero_flag_s(char *a)
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

static char			*minus_flag_s(char *m)
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

void				con_s(va_list options, t_flags *flags, t_val *val)
{
	char			*com;

	com = (char*)ft_memalloc(sizeof(flags));
	if (flags->length)
	{
		if (ft_strcmp(flags->length, "l") == 0)
			com = l_flag_s(va_arg(options, long));
		if (ft_strcmp(flags->length, "ll") == 0)
			com = ll_flag_s(va_arg(options, long long));
		if (ft_strcmp(flags->length, "h") == 0)
			*com = (short)h_flag_s(va_arg(options, int));
		if (ft_strcmp(flags->length, "hh") == 0)
			*com = (char)hh_flag_s(va_arg(options, int));
	}
	if (!flags->length)
		com = va_arg(options, char*);
	if (flags->precis > 0)
		com = precision_s(flags->precis, com);
	if (flags->width > 0)
		com = width_s(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_s(com);
	if (flags->minus == 1)
		com = minus_flag_s(com);
	val->k += ft_putstr(com);
}
