/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/19 23:51:43 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

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

static char			*wzm_help(int wid, char *ans, t_flags *flag, int i)
{
	int				h;

	while (wid >= 0 && flag->minus == 0 && flag->width >= 1)
	{
		ans[wid] = ' ';
		wid--;
	}
	flag->width = 0;
	h = ft_strlen(ans);
	while (i >= 0 && flag->minus == 1)
	{
		ans[h++] = ' ';
		i--;
	}
	flag->minus = 0;
	h = ft_strlen(ans) - 1;
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1
			&& flag->precis == 0)
		h--;
	while (ans[h] && flag->zero == 1 && flag->precis == 0)
	{
		ans[h] = '0';
		h--;
	}
	flag->zero = 0;
	return (ans);
}

static char			*wid_zer_min_o(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	if (flag->minus == 1)
		i = -1;
	else
		i = ft_strlen(s);
	wid--;
	if (wid < (int)ft_strlen(s))
		return (s);
	if (i == -1)
	{
		while (s[++i])
			ans[i] = s[i];
		wid -= i;
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

static char			*hash_o(char *s)
{
	char			*str;

	str = ft_strnew(ft_strlen(s));
	str[0] = '0';
	if (*s == '0')
		return (s);
	else if (*s >= 1 || ft_isalpha(*s) == 1)
		str = ft_strjoin(str, s);
	return (str);
}

void				con_o(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, uint64_t);
	else
		a = va_arg(options, uint32_t);
	com = ft_itoa_o_unsigned(a);
	if (flags->precis > 0)
		com = precision_o(flags->precis, com);
	if (flags->hash == 1)
		com = hash_o(com);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_o(flags->width, com, flags);
	val->k += ft_putstr(com);
}
