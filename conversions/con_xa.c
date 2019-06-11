/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_xa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:55 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 16:59:18 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_xa(int perc, char *point)
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

static char			*zero_flag_xa(char *a)
{
	int				i;

	i = ft_strlen(a) - 1;
	while ((ft_isdigit(a[i]) == 1) || (ft_isdigit(a[i]) == 1) || (a[i] == '-'))
		i--;
	while ((ft_is_space(a[i]) == 1) && a[i])
	{
		a[i] = '0';
		i--;
	}
	return (a);
}

static char			*width_xa(int wid, char *s)
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
	while (wid > 0)
	{
		ans[j] = (' ');
		wid--;
		j--;
	}
	return (ans);
}

static char			*minus_flag_xa(char *m)
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

void				con_xa(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, int64_t);
	else
		a = va_arg(options, int32_t);
	com = ft_itoa_cx(a);
	if (*com == '-')
	{
		flags->sign = 1;
		com++;
	}
	if (flags->precis > 0)
		com = precision_xa(flags->precis, com);
	if (flags->width > 0)
		com = width_xa(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_xa(com);
	if (flags->minus == 1)
		com = minus_flag_xa(com);
	val->k += ft_putstr(com);
}
