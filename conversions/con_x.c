/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 01:04:16 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_x(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc < i)
		return (ft_strdup(point));
	if (!perc)
		perc = 0;
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

static char			*hash_x(char *s)
{
	if ((ft_atoi(s) > 0 || (ft_isalpha(*s) == 1)))
		s = ft_ccstrjoini('0', 'x', s);
	return (ft_strdup(s));
}

static void			wzm_help(int wid, char *ans, t_flags *flag)
{
	int				h;
	int				k;

	k = wid;
	while (wid > 0 && !flag->minus)
	{
		--wid;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && flag->minus)
	{
		--wid;
		ans[h++] = ' ';
	}
	while (ft_isdigit(ans[k]) == 1 && flag->zero && !flag->precis)
		k--;
	while (ans[k] && flag->zero && !flag->precis)
	{
		ans[k] = '0';
		k--;
	}
}

static char			*wid_zer_min_x(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	if (wid < (int)ft_strlen(s))
	{
		ans = flag->hash ? ft_strdup(hash_x(s)) : 0;
		return (flag->hash ? ans : ft_strdup(s));
	}
	i = flag->minus? -1 : ft_strlen(s);
	ans = ft_strnew(wid);
	if (flag->minus)
		while (s[++i] && wid--)
			ans[i] = s[i];
	else
		while (i-- > 0)
			ans[--wid] = s[i];
	wzm_help(wid, ans, flag);
	if (flag->hash)
		ans = hash_x(ans);
	return (ans);
}

void				con_x(va_list options, t_flags *flags, t_val *val)
{
	uint64_t		a;
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	a = (ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t);
	com = ft_itoa_x(a);
	if (flags->precis > 0 || flags->precis == -1)
	{
		tmp = freeing(com, tmp);
		com = precision_x(flags->precis, tmp);
	}
	if (flags->width >= 1)
	{
		tmp = freeing(com, tmp);
		com = wid_zer_min_x(flags->width, tmp, flags);
	}
	if (flags->hash && !flags->width)
	{
		tmp = freeing(com, tmp);
		com = hash_x(tmp);
	}
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
