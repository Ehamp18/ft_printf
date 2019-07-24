/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:30 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/23 19:16:55 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_p(int perc, char *point)
{
	int				i;
	char			*res;
	int				j;

	j = perc;
	res = ft_strnew(perc);
	i = ft_strlen(point);
	if (perc < i)
		return (point);
	if (!perc)
		perc = 0;
	while (perc >= 0)
	{
		res[perc] = '0';
		perc--;
	}
	while (i >= 0 && perc)
	{
		res[j] = point[i];
		i--;
		j--;
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

static char			*wid_zer_min_p(int wid, char *s, t_flags *flag)
{
	int				i;
	int				j;
	char			*ans;

	if (wid-- < (int)ft_strlen(s) - 1)
		return (s);
	ans = ft_strnew(wid);
	j = -1;
	i = flag->minus == 1 ? 0 : ft_strlen(s);
	if (flag->minus == 1)
	{
		while (s[i++])
			if (ft_isdigit(s[i]) == 1 || ft_isalpha(s[i]))
				ans[++j] = s[i];
		wid -= j;
	}
	else
		while (i-- > 0 && wid--)
			ans[wid] = s[i];
	i = wid;
	wzm_help(wid, ans, flag, i);
	return (ans);
}

void				con_p(va_list options, t_flags *flags, t_val *val)
{
	intptr_t		a;
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	a = va_arg(options, intptr_t);
	com = ft_itoa_u_p(a);
	if (flags->precis > 0)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = precision_p(flags->precis, tmp);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = wid_zer_min_p(flags->width, tmp, flags);
	}
	tmp = ft_strcpy(tmp, com);
	free(com);
	com = ft_ccstrjoin('0', 'x', tmp);
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
}
