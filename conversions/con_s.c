/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/14 21:49:49 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

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
	int64_t			a;
	char			*com;

	com = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, int64_t);
	else
		a = va_arg(options, int32_t);
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
