/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:50:06 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/09 22:03:47 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_b(int perc, char *point)
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

static char			*width_b(int wid, char *s)
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

static char			*space_flag_b(char *a)
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

static char			*zero_flag_b(char *a)
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

static char			*plus_flag_b(char *a, int i)
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

static char			*minus_flag_b(char *m)
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

void				con_b(va_list options, t_flags *flags, t_val *val)
{
	char			*com;

	com = (char*)ft_memalloc(sizeof(flags));
	com = ft_itoa_b(va_arg(options, int));
	if (flags->precis > 0)
		com = precision_b(flags->precis, com);
	if (flags->width > 0)
		com = width_b(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_b(com);
	if (flags->space == 1)
		com = space_flag_b(com);
	if (flags->plus == 1)
		com = plus_flag_b(com, flags->sign);
	if (flags->minus == 1)
		com = minus_flag_b(com);
	val->k += ft_putstr(com);
}
