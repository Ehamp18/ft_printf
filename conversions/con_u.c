/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/01 23:17:07 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_u(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(ft_numlen(perc) + 1);
	i = ft_strlen(point);
	if (perc == -1)
		return (res);
	if (perc < (int)ft_strlen(point))
		return (ft_strdup(point));
	while (i >= 0)
	{
		res[perc] = point[i--];
		perc--;
	}
	while (perc >= 0)
	{
		res[perc] = '0';
		perc--;
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

static char			*wid_zer_min_u(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	RETY((wid-- < (int)ft_strlen(s)), ft_strdup(s));
	if (flag->minus)
	{
		while (s[++i])
			if (ft_isdigit(s[i]) == 1 || s[i] == '-')
			{
				ans[i] = s[i];
				wid--;
			}
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

static char			*spac_plus_u(char *a, t_flags *flag)
{
	char			*res;

	if (flag->plus)
		res = a[0] != '-' ? ft_cstrjoin('+', a) : ft_cstrjoin('-', a);
	else
		res = a[0] != '-' ? ft_cstrjoin(' ', a) : ft_cstrjoin('-', a);
	return (ft_strdup(res));
}

void				con_u(va_list options, t_flags *flags, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_unsigned((ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t));
	if (flags->precis > 0)
	{
		tmp = freeing(com, tmp);
		com = precision_u(flags->precis, tmp);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		tmp = freeing(com, tmp);
		com = wid_zer_min_u(flags->width, tmp, flags);
	}
	if (flags->space == 1 || flags->plus == 1)
	{
		tmp = freeing(com, tmp);
		com = spac_plus_u(tmp, flags);
	}
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
