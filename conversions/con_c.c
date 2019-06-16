/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/15 20:49:20 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

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
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1)
		h--;
	while (ans[h] && flag->zero == 1)
	{
		ans[h] = '0';
		h--;
	}
	flag->zero = 0;
	return (ans);
}

static char			*wid_zer_min_c(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	if (flag->minus == 1)
		i = -1;
	else
		i = ft_strlen(s);
	wid--;
	while (flag->minus == 1 || flag->width >= 1 || flag->zero == 1)
	{
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
	}
	return (ans);
}

static char			*spac_plus_c(char *a, t_flags *flag)
{
	char			*s;
	char			*res;

	s = ft_strnew(ft_strlen(a));
	if (flag->plus == 0)
	{
		*s = '-';
		if (a[0] != '-')
			*s = ' ';
		res = ft_strjoin(s, a);
	}
	else
	{
		if (*s != '-')
			*s = '+';
		else
			*s = '-';
		res = ft_strjoin(s, a);
	}
	return (res);
}

void				con_c(va_list options, t_flags *flags, t_val *val)
{
	wint_t			a;
	char			*com;

	a = 0;
	com = ft_strnew(sizeof(char*));
	if (ft_strcmp(flags->length, "l") == 0)
		a = va_arg(options, wint_t);
	else
		*com = (char)va_arg(options, int);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_c(flags->width, com, flags);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_c(com, flags);
	val->k += ft_putstr(com);
}
