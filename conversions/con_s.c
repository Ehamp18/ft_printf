/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/04 02:43:16 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_s(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	i = 0;
	if (perc == -1)
		return (res);
	while (point[i] && perc > 0)
	{
		res[i] = point[i];
		i++;
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
	while ((ft_isdigit(ans[h]) || ans[h] == '-') && fl->zero)
		h--;
	while (ans[h] && fl->zero)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_s(int wid, char *s, t_flags *fl)
{
	int				i;
	char			*ans;

	i = fl->minus ? -1 : ft_strlen(s);
	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	if (fl->minus)
		while (s[++i])
		{
			ans[i] = s[i];
			wid--;
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

void				con_s(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	if (fl->length == 108)
		com = (char*)va_arg(options, wchar_t*);
	else if (!(com = ft_strdup(va_arg(options, char*))))
		com = ft_strdup("(null)");
	if (fl->precis || fl->precis == -1)
	{
		tmp = freeing(com, tmp);
		com = precision_s(fl->precis, tmp);
	}
	if (fl->width)
	{
		tmp = freeing(com, tmp);
		com = wid_zer_min_s(fl->width, tmp, fl);
	}
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
