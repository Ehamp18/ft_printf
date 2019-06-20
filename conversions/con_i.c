/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/19 23:41:00 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_i(int perc, char *point, t_val *val)
{
	int				i;
	char			*res;
	int				j;

	j = perc;
	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc == -1)
		return (0);
	if (perc <= i)
		return (point);
	while (i >= 0 && j)
	{
		if (point[i] == '-')
		{
			point[i] = '0';
			val->zero = 1;
		}
		res[j] = point[i];
		i--;
		j--;
		perc--;
	}
	while (j >= 0)
	{
		res[j] = '0';
		j--;
	}
	return (res);
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
	while (i >= 0 && flag->minus == 1)
	{
		ans[h++] = ' ';
		i--;
	}
	h = ft_strlen(ans) - 1;
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1
			&& flag->precis == 0)
		h--;
	while (ans[h] && flag->zero == 1 && flag->precis == 0)
	{
		ans[h] = '0';
		h--;
	}
	return (ans);
}

static char			*wid_zer_min_i(int wid, char *s, t_flags *flag)
{
	int				i;
	int				j;
	char			*ans;

	j = 0;
	ans = ft_strnew(wid);
	if (flag->minus == 1)
		i = 0;
	else
		i = ft_strlen(s);
	wid--;
	if (wid < (int)ft_strlen(s))
		return (s);
	if (flag->minus == 1)
	{
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 1 || s[i] == '-')
			{
				ans[j] = s[i];
				j++;
			}
			i++;
		}
		wid -= j;
	}
	else
		while (i-- > 0)
		{
			ans[wid] = s[i];
			wid--;
		}
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	return (ans);
}

static char			*spac_plus_i(char *a, t_flags *flag, t_val *val)
{
	char			*s;
	char			*res;
	int				i;

	i = 0;
	s = ft_strnew(ft_strlen(a));
	res = ft_strnew(ft_strlen(a));
	if (flag->plus == 1)
	{
		while (a[i] == ' ' || ft_isdigit(a[i]) == 0)
			i++;
		if (s[i] != '-' && val->zero != 1)
			s[i] = '+';
		else
			val->zero = 1;
		res = ft_strjoin(s, a);
	}
	else
	{
		if (a[0] != '-')
			*s = ' ';
		res = ft_strjoin(s, a);
	}
	return (res);
}

void				con_i(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;
	char			*s;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, int64_t);
	else
		a = va_arg(options, int32_t);
	com = ft_itoa(a);
	s = ft_strnew(ft_strlen(com));
	if (flags->precis > 0 || flags->precis == -1)
		com = precision_i(flags->precis, com, val);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_i(com, flags, val);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_i(flags->width, com, flags);
	if (val->zero == 1)
	{
		*s = '-';
		com = ft_strjoin(s, com);
	}
	val->k += ft_putstr(com);
}
