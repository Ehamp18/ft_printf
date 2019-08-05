/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:50:06 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 19:57:44 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_b(int perc, char *point)
{
	int				i;
	char			*res;

	if (perc <= (int)ft_strlen(point))
		return (ft_strdup(point));
	if (perc == -1)
		return (0);
	res = ft_strnew(perc);
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
	while (ft_isdigit(ans[h]) && fl->zero && !fl->precis)
		h--;
	while (ans[h] == ' ' && fl->zero && !fl->precis)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_b(int wid, char *s, t_flags *fl)
{
	int				i;
	char			*ans;

	i = fl->minus ? -1 : ft_strlen(s);
	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	if (fl->minus)
	{
		while (s[++i])
			if (ft_isdigit(s[i]) && wid--)
				ans[i] = s[i];
	}
	else
		while (i-- > 0)
			ans[--wid] = s[i];
	wzm_help(wid, ans, fl);
	return (ans);
}

void				con_b(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_b((fl->length == 108 || fl->length == 216) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t));
	if (fl->precis || fl->precis == -1)
	{
		tmp = freeing(com, tmp);
		com = precision_b(fl->precis, tmp);
	}
	if (fl->width)
	{
		tmp = freeing(com, tmp);
		com = wid_zer_min_b(fl->width, tmp, fl);
	}
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
