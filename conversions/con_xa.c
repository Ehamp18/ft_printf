/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_xa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:55 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 19:43:43 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_x(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc <= i)
		return (ft_strdup(point));
	if (!perc)
		perc = 0;
	while (i >= 0 && perc)
	{
		res[perc] = point[i];
		i--;
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
	int				k;

	k = wid;
	while (wid > 0 && !fl->minus && fl->width)
	{
		--wid;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && fl->minus)
	{
		wid--;
		ans[h++] = ' ';
	}
	while ((ft_isdigit(ans[k]) || ans[k] == '-') && fl->zero && !fl->precis)
		k--;
	while (ans[k] && fl->zero == 1 && fl->precis == 0)
	{
		ans[k] = '0';
		k--;
	}
}

static char			*wid_zer_min_x(int wid, char *s, t_flags *fl)
{
	int				i;
	char			*ans;

	i = fl->minus == 1 ? -1 : ft_strlen(s);
	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	if (fl->minus)
		while (s[++i] && wid--)
			ans[i] = s[i];
	else
		while (i-- > 0)
			ans[--wid] = s[i];
	wzm_help(wid, ans, fl);
	return (ans);
}

static char			*hash_x(char *s)
{
	if ((ft_atoi(s) > 0 || ft_isalpha(*s)) && *s != 0)
		s = ft_ccstrjoini('0', 'X', s);
	return (ft_strdup(s));
}

void				con_xa(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_cx((fl->length == 108 || fl->length == 216) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t));
	if (fl->precis || fl->precis == -1)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = precision_x(fl->precis, tmp);
	}
	if (fl->hash)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = hash_x(tmp);
	}
	if (fl->width)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_x(fl->width, tmp, fl);
	}
	FREE2((val->k += ft_putstr(com)), com, tmp);
}
