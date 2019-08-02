/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:45 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/01 01:18:26 by elhampto         ###   ########.fr       */
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
	while (i >= 0 && perc)
	{
		res[perc] = point[i];
		i--;
		perc--;
	}
	while (perc > 0)
	{
		res[perc] = '0';
		perc--;
	}
	return (res);
}

static char			*hash_x(char *s, t_flags *flag)
{
	if ((ft_atoi(s) > 0 || (ft_isalpha(*s) == 1)) && *s)
		s = ft_ccstrjoini('0', 'x', s, flag);
	return (ft_strdup(s));
}

static void			wzm_help(int wid, char *ans, t_flags *flag)
{
	int				h;
	int				k;

	k = wid;
	while (wid > 0 && flag->minus == 0 && flag->width >= 1)
	{
		--wid;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && flag->minus == 1)
	{
		wid--;
		ans[h++] = ' ';
	}
	while ((ft_isdigit(ans[k]) == 1 || ans[k] == '-') && flag->zero == 1 &&
		flag->precis == 0)
		k--;
	while (ans[k] && flag->zero == 1 && flag->precis == 0)
	{
		ans[k] = '0';
		k--;
	}
}

static char			*wid_zer_min_x(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	i = flag->minus == 1 ? -1 : ft_strlen(s);
	ans = ft_strnew(wid);
	if (wid < (int)ft_strlen(s))
	{
		if (flag->hash)
			ans = hash_x(s, flag);
		return (flag->hash ? ans : ft_strdup(s));
	}
	if (flag->minus)
		while (s[++i])
		{
			DEC((ans[i] = s[i]), wid);
		}
	else
		while (i-- > 0)
			DEC((ans[wid] = s[i]), wid);
	wzm_help(wid, ans, flag);
	if (flag->hash == 1)
		ans = (flag->width >= 1 || flag->minus) ?
			hash_x(ans, flag) : hash_x(s, flag);
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
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = precision_x(flags->precis, tmp);
	}
	if (flags->hash == 1 || flags->width >= 1 || flags->minus == 1 ||
		flags->zero == 1)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_x(flags->width, tmp, flags);
	}
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
}
