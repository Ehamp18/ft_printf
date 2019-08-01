/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:50:06 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/30 14:19:45 by elhampto         ###   ########.fr       */
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

static void			wzm_help(int wid, char *ans, t_flags *flag, int i)
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
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1 &&
			flag->precis == 0)
		h--;
	while (ans[h] == ' ' && flag->zero == 1 && flag->precis == 0)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_b(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	i = flag->minus == 1 ? -1 : ft_strlen(s);
	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	if (flag->minus)
	{
		while (s[++i])
			if (ft_isdigit(s[i]) == 1 || s[i] == '+')
			{
				ans[i] = s[i];
				wid--;
			}
	}
	else
		while (i-- > 0)
			DEC((ans[wid] = s[i]), wid);
	i = wid;
	wzm_help(wid, ans, flag, i);
	return (ans);
}

void				con_b(va_list options, t_flags *flags, t_val *val)
{
	int64_t			a;
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	a = (ft_strcmp(flags->length, "l") == 0) ||
		(ft_strcmp(flags->length, "ll") == 0) ?
		va_arg(options, uint64_t) : va_arg(options, uint32_t);
	com = ft_itoa_b(a);
	if (flags->precis > 0 || flags->precis == -1)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = precision_b(flags->precis, tmp);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = wid_zer_min_b(flags->width, tmp, flags);
	}
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
}
