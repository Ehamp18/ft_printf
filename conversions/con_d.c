/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/04 02:56:25 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_d(int perc, char *point, t_val *val)
{
	int				i;
	char			*res;

	i = ft_strlen(point);
	RETY(perc <= i, ft_strdup(point));
	res = ft_strnew(perc);
	if (perc == -1)
		return (res);
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
	while (perc >= 0)
	{
		res[perc] = '0';
		perc--;
	}
	return (val->in == -1 ? ft_cstrjoin('-', res) : res);
}

static void			wzm_help(int wid, char *ans, t_flags *fl)
{
	int				h;

	while (wid >= 0 && !fl->minus && fl->width)
	{
		ans[wid] = ' ';
		wid--;
	}
	h = ft_strlen(ans);
	while (wid >= 0 && fl->minus)
	{
		ans[h++] = ' ';
		wid--;
	}
	h = ft_strlen(ans) - 1;
	if (!fl->precis && !fl->minus && fl->zero)
	{
		while ((ft_isdigit(ans[h]) || ans[h] == '-'))
			h--;
		while (ans[h] == ' ' && fl->zero)
			DEC((ans[h] = '0'), h);
	}
	if (fl->si == '-')
		ans[0] = '-';
}

static char			*wid_zer_min_d(int wid, char *s, t_flags *fl, t_val *val)
{
	char			*ans;

	fl->si = ' ';
	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	wid--;
	if (fl->minus)
	{
		ans = min_help(s, ans, fl, val);
		wid -= val->count;
	}
	else
	{
		val->wid = wid;
		ans = min_help2(s, ans, fl, val);
		wid = val->wid;
	}
	wzm_help(wid, ans, fl);
	return (ans);
}

static char			*spac_plus_d(char *a, t_flags *fl, t_val *val)
{
	char			*res;
	int				i;

	i = -1;
	while (a[++i])
		if (a[i] == '-')
			return (ft_strdup(a));
	if (fl->plus)
		res = !val->zero ? ft_cstrjoini('+', a, fl) : ft_cstrjoini('-', a, fl);
	else
		res = !val->zero ? ft_cstrjoini(' ', a, fl) : ft_cstrjoini('-', a, fl);
	return (res);
}

void				con_d(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa((fl->length == 108 || fl->length == 216) ?
		va_arg(options, int64_t) : va_arg(options, int32_t));
	ONE(ft_atoi(com) < 0, val->zero);
	if (fl->precis || fl->precis == -1)
	{
		tmp = freeing(com, tmp);
		com = precision_d(fl->precis, tmp, val);
	}
	if (fl->width)
	{
		tmp = freeing(com, tmp);
		com = wid_zer_min_d(fl->width, tmp, fl, val);
	}
	if (fl->space || fl->plus)
	{
		tmp = freeing(com, tmp);
		com = spac_plus_d(tmp, fl, val);
	}
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
