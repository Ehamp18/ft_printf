/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_%.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:42:18 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/09 23:32:02 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_pre(int perc, char *point)
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

static char			*width_pre(int wid, char *s)
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

static char			*space_flag_pre(char *a)
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

static char			*zero_flag_pre(char *a)
{
	int				i;

	i = ft_strlen(a) - 1;
	while (a[i] == '%')
		i--;
	while ((ft_is_space(a[i]) == 1) && a[i])
	{
		a[i] = '0';
		i--;
	}
	return (a);
}

static char			*plus_flag_pre(char *a, int i)
{
	char			*s;
	char			*res;
	int				j;

	j = 0;
	s = ft_strnew(ft_strlen(a));
	while (*a == '%')
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

static char			*minus_flag_pre(char *m)
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

void				con_per(t_flags *flags, t_val *val)
{
	char			*com;

	com = (char*)ft_memalloc(sizeof(flags));
	*com = '%';
	if (flags->precis > 0)
		com = precision_pre(flags->precis, com);
	if (flags->width > 0)
		com = width_pre(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_pre(com);
	if (flags->space == 1)
		com = space_flag_pre(com);
	if (flags->plus == 1)
		com = plus_flag_pre(com, flags->sign);
	if (flags->minus == 1)
		com = minus_flag_pre(com);
	val->k += ft_putstr(com);
}