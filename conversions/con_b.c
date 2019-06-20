/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:50:06 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/19 23:54:13 by elhampto         ###   ########.fr       */
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
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1 &&
			flag->precis == 0)
		h--;
	while (ans[h] == ' ' && flag->zero == 1 && flag->precis == 0)
	{
		ans[h] = '0';
		h--;
	}
	return (ans);
}

static char			*wid_zer_min_b(int wid, char *s, t_flags *flag)
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

static char			*spac_plus_b(char *a, t_flags *flag, t_val *val)
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

void				con_b(va_list options, t_flags *flags, t_val *val)
{
	char			*com;
	char			*s;

	com = (char*)ft_memalloc(sizeof(flags));
	com = ft_itoa_b(va_arg(options, int));
	s = ft_strnew(ft_strlen(com));
	if (flags->precis > 0 || flags->precis == -1)
		com = precision_b(flags->precis, com);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_b(com, flags, val);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_b(flags->width, com, flags);
	if (val->zero == 1)
	{
		*s = '-';
		com = ft_strjoin(s, com);
	}
	val->k += ft_putstr(com);
}
