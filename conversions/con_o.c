/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 00:36:55 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_o(int perc, char *point)
{
	int				i;
	char			*res;

	res = ft_strnew(perc);
	if (perc == 0)
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

static char			*wzm_help(int wid, char *ans, t_flags *flag, int i)
{
	int				h;

	while (wid > 0 && flag->minus == 0 && flag->width >= 1)
	{
		wid--;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (i > 0 && flag->minus == 1)
	{
		i--;
		ans[h++] = ' ';
	}
	h = ft_strlen(ans) - 1;
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1
			&& flag->precis == 0)
		h--;
	while (ans[h] && flag->zero == 1 && !flag->precis && !flag->minus)
	{
		ans[h] = '0';
		h--;
	}
	return (ans);
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
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	return (ans);
}

static char			*hash_o(char *s)
{
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	if (ft_atoi(s) == 0)
		return (s);
	else if (*s >= 1 || ft_isalpha(*s) == 1)
		s = ft_cstrjoin('0', s);
	free(tmp);
	return (ft_strdup(s));
}

void				con_o(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	a = (ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0) ?
		va_arg(options, unsigned long long) : va_arg(options, unsigned long);
	com = ft_itoa_o_unsigned(a);
	if (flags->precis > 0)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = precision_o(flags->precis, tmp);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_o(flags->width, tmp, flags);
	}
	if (flags->hash == 1)
		com = hash_o(com);
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
}
