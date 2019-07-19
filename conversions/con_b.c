/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:50:06 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/18 23:49:14 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"
#include <stdio.h>

static char			*precision_b(int perc, char *point)
{
	int				i;
	char			*res;

	if (!perc || perc < (int)ft_strlen(point))
		return (point);
	if (perc == -1)
		return (0);
	res = ft_strnew(ft_numlen(perc));
	i = ft_strlen(point);
	while (i >= 0)
	{
		res[perc] = point[i--];
		perc--;
	}
	while (perc >= 0)
	{
		res[perc] = ('0');
		perc--;
	}
	free(point);
	return (res);
}

static void			wzm_help(int wid, char *ans, t_flags *flag, int i)
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
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1 &&
			flag->precis == 0)
		h--;
	while (ans[h] == ' ' && flag->zero == 1 && flag->precis == 0)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_b(int wid, char *s, t_flags *flag)
{
	int				i;
	int				j;
	char			*ans;

	j = 0;
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	wid--;
	if (wid < (int)ft_strlen(s))
		return (s);
	ans = ft_strnew(wid);
	if (flag->minus == -1)
	{
		while (s[++i])
			if (ft_isdigit(s[i]) == 1 || s[i] == '+')
				ans[j++] = s[i];
		wid -= j;
	}
	else
		while (i-- > 0)
			DEC((ans[wid] = s[i]), wid);
	i = wid;
	wzm_help(wid, ans, flag, i);
	free(s);
	return (ans);
}

static char			*spac_plus_b(char *a, t_flags *flag, t_val *val)
{
	char			*res;
	int				i;

	i = 0;
	res = ft_strnew(ft_strlen(a));
	if (flag->plus == 1)
	{
		while (a[i] == ' ' || ft_isdigit(a[i]) == 0)
			i++;
		if (!val->zero)
			res = ft_cstrjoin('+', a);
		else
			res = ft_cstrjoin('-', a);
	}
	else
	{
		while (a[i] == ' ' || ft_isdigit(a[i]) == 0)
			i++;
		if (!val->zero)
			res = ft_cstrjoin('+', a);
		else
			res = ft_cstrjoin('-', a);
	}
	return (res);
}

void				con_b(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	a = (ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t);
	com = ft_itoa_b(a);
	if (flags->precis > 0 || flags->precis == -1)
		com = precision_b(flags->precis, com);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_b(com, flags, val);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_b(flags->width, com, flags);
	val->k += ft_putstr(com);
	free(com);
}
