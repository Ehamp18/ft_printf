/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/18 17:25:42 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"
#include <stdio.h>

static char			*precision_u(int perc, char *point)
{
	int				i;
	char			*res;
	int				j;

	res = ft_strnew(ft_numlen(perc));
	j = ft_numlen(perc);
	i = ft_strlen(point);
	if (perc == -1)
		return ("\0");
	if (perc < (int)ft_strlen(point))
		return (point);
	perc -= i;
	while (i >= 0)
	{
		res[j] = point[i];
		i--;
		j--;
	}
	while (perc > 0)
	{
		res[j] = '0';
		perc--;
		j--;
	}
	free(point); //made me fail 5 test
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

static char			*wid_zer_min_u(int wid, char *s, t_flags *flag)
{
	int				i;
	int				j;
	char			*ans;

	ans = ft_strnew(wid);
	j = 0;
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	if (wid-- < (int)ft_strlen(s))
		return (s);
	if (i == -1)
	{
		while (s[++i])
			if (ft_isdigit(s[i]) == 1 || s[i] == '-')
				ans[j++] = s[i];
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
	free(s); // Made me fail 3 test
	return (ans);
}

static char			*spac_plus_u(char *a, t_flags *flag)
{
	char			*res;

	if (flag->plus == 0)
	{
		if (a[0] != '-')
			res = ft_cstrjoin('+', a);
		else
			res = ft_cstrjoin('-', a);
	}
	else
	{
		if (a[0] != '-')
			res = ft_cstrjoin('+', a);
		else
			res = ft_cstrjoin('-', a);
	}
	return (res);
}

void				con_u(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;

	a = 0;
	if ((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0))
		a = va_arg(options, uint64_t);
	else
		a = va_arg(options, uint32_t);
	com = ft_itoa_unsigned(a);
	if (flags->precis > 0)
		com = precision_u(flags->precis, com);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_u(flags->width, com, flags);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_u(com, flags);
	val->k += ft_putstr(com);
	free(com); // made me fail 1 test
}
