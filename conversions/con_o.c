/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 18:37:02 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_o(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	if (!perc)
		return (res);
	if (perc <= (int)ft_strlen(point))
		return (ft_strdup(point));
	i = ft_strlen(point);
	while (i >= 0)
	{
		res[perc] = point[i];
		i--;
		perc--;
	}
	while ((perc >= 0))
	{
		res[perc] = ('0');
		perc--;
	}
	return (res);
}

static void			wzm_help(int wid, char *ans, t_flags *flag)
{
	int				h;

	while (wid > 0 && !flag->minus && flag->width)
	{
		wid--;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && flag->minus)
	{
		wid--;
		ans[h++] = ' ';
	}
	h = ft_strlen(ans) - 1;
	while ((ft_isdigit(ans[h]) || ans[h] == '-') && flag->zero && flag->precis)
		h--;
	while (ans[h] && flag->zero && !flag->precis && !flag->minus)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_o(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	i = flag->minus == 1 ? -1 : ft_strlen(s);
	if (wid <= (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	if (flag->minus)
		while (s[++i])
		{
			ans[i] = s[i];
			wid--;
		}
	else
		while (i-- > 0)
		{
			ans[wid] = s[i];
			wid--;
		}
	wzm_help(wid, ans, flag);
	return (ans);
}

static char			*hash_o(char *s)
{
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	if (!ft_atoi(s))
		return (s);
	else if (*s >= 1 || ft_isalpha(*s))
		s = ft_cstrjoin('0', s);
	free(tmp);
	return (ft_strdup(s));
}

void				con_o(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_o_unsigned((fl->length == 108 || fl->length == 216) ?
		va_arg(options, unsigned long long) : va_arg(options, unsigned long));
	if (fl->precis)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = precision_o(fl->precis, tmp);
	}
	if (fl->width)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_o(fl->width, tmp, fl);
	}
	if (fl->hash)
		com = hash_o(com);
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
}
