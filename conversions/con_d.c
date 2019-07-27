/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/26 16:19:25 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_d(int perc, char *point, t_val *val)
{
	int				i;
	char			*res;

	val->in = 1;
	i = ft_strlen(point);
	if (perc <= i)
		return (ft_strdup(point));
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

static char			*wzm_help(int wid, char *ans, t_flags *flag, int i)
{
	int				h;

	while (wid >= 0 && flag->minus == 0 && flag->width >= 1)
	{
		ans[wid] = ' ';
		wid--;
	}
	h = ft_strlen(ans);
	while (i-- >= 0 && flag->minus == 1)
		ans[h++] = ' ';
	h = ft_strlen(ans) - 1;
	if (flag->precis == 0 && flag->minus == 0 && flag->zero == 1)
	{
		while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-'))
			h--;
		while (ans[h] == ' ' && flag->zero == 1)
		{
			ans[h] = '0';
			h--;
		}
	}
	if (flag->si == '-')
		ans[0] = '-';
	return (ans);
}

static char			*wid_zer_min_d(int wid, char *s, t_flags *flag, t_val *val)
{
	int				i;
	char			*ans;

	flag->si = ' ';
	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	wid--;
	if (flag->minus == 1)
	{
		ans = min_help(s, ans, flag, val);
		wid -= val->count;
	}
	else
	{
		val->wid = wid;
		ans = min_help2(s, ans, flag, val);
		wid = val->wid;
	}
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	return (ans);
}

static char			*spac_plus_d(char *a, t_flags *flag, t_val *val)
{
	char			*res;
	int				i;

	i = 0;
	while (a[i])
	{
		if (a[i] == '-')
			return (ft_strdup(a));
		i++;
	}
	if (flag->plus)
		res = !val->zero ?
			ft_cstrjoini('+', a, flag) : ft_cstrjoini('-', a, flag);
	else
		res = !val->zero ?
			ft_cstrjoini(' ', a, flag) : ft_cstrjoini('-', a, flag);
	return (res);
}

void				con_d(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;
	char			*tmp;

	a = 0;
	tmp = ft_strnew(sizeof(char));
	a = (ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0) ?
		va_arg(options, int64_t) : va_arg(options, int32_t);
	com = ft_itoa(a);
	if (a < 0)
		val->zero = 1;
	if (flags->precis > 0 || flags->precis == -1)
	{
		free(tmp);
		ft_bzero(tmp, ft_strlen(tmp));
		tmp = ft_strjoin(tmp, com);
		free(com);
		com = precision_d(flags->precis, tmp, val);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		free(tmp);
		ft_bzero(tmp, ft_strlen(tmp));
		tmp = ft_strjoin(tmp, com);
		free(com);
		com = wid_zer_min_d(flags->width, tmp, flags, val);
	}
	if (flags->space == 1 || flags->plus == 1)
	{
		free(tmp);
		ft_bzero(tmp, ft_strlen(tmp));
		tmp = ft_strjoin(tmp, com);
		free(com);
		com = spac_plus_d(tmp, flags, val);
	}
	val->k += ft_putstr(com);
	free(tmp);
	free(com);
}
