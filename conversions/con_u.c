/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 19:30:27 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_u(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(ft_unumlen(perc));
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

static void			wzm_help(int wid, char *ans, t_flags *fl)
{
	int				h;

	while (wid > 0 && !fl->minus && fl->width)
	{
		wid--;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && fl->minus)
	{
		wid--;
		ans[h++] = ' ';
	}
	h = ft_strlen(ans) - 1;
	while (ft_isdigit(ans[h]) && fl->zero && !fl->precis)
		h--;
	while (ans[h] && fl->zero && !fl->precis)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_u(int wid, char *s, t_flags *fl)
{
	int				i;
	char			*ans;

	i = fl->minus ? -1 : ft_strlen(s);
	RETY((wid < (int)ft_strlen(s)), ft_strdup(s));
	ans = ft_strnew(wid);
	if (fl->minus)
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
			wid--;
			ans[wid] = s[i];
		}
	wzm_help(wid, ans, fl);
	return (ans);
}

void				con_u(va_list options, t_flags *fls, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_unsigned((fls->length == 108 || fls->length == 216) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t));
	if (fls->precis)
	{
		tmp = freeing(com, tmp);
		com = precision_u(fls->precis, tmp);
	}
	if (fls->width)
	{
		tmp = freeing(com, tmp);
		com = wid_zer_min_u(fls->width, tmp, fls);
	}
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
