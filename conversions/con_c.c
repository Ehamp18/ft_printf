/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/18 23:20:30 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*wzm_help(int wid, char *ans, t_flags *flag, int i)
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
	while ((ft_isdigit(ans[h]) == 1 || ans[h] == '-') && flag->zero == 1)
		h--;
	while (ans[h] && flag->zero == 1)
	{
		ans[h] = '0';
		h--;
	}
	return (ans);
}

static char			*wid_zer_min_c(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	if (wid-- < ((int)ft_strlen(s) - 1))
		return (s);
	if (i == -1)
	{
		while (s[++i])
			ans[i] = s[i];
		wid -= i;
	}
	else
		while (i-- > 0)
		{
			ans[wid] = s[i];
			wid--;
		}
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	free(s);
	return (ans);
}

static char			*spac_plus_c(char *a, t_flags *flag)
{
	char			*res;

	if (flag->plus == 0)
	{
		if (a[0] != '-')
			res = ft_cstrjoin('+', a);
		else
			res = ft_cstrjoin('-', a);
	}
	else
	{
		if (a[0] != '-')
			res = ft_cstrjoin('+', a);
		else
			res = ft_cstrjoin('-', a);
	}
	return (res);
}

void				con_c(va_list options, t_flags *flags, t_val *val)
{
	char			*com;
	int				si;

	si = 0;
	com = ft_strnew(sizeof(char*));
	*com = ft_strcmp(flags->length, "l") == 0 ?
		va_arg(options, wint_t) : va_arg(options, int);
	if (*com == 0)
		si = 1;
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
		com = wid_zer_min_c(flags->width, com, flags);
	if (flags->space == 1 || flags->plus == 1)
		com = spac_plus_c(com, flags);
	if (si == 1)
	{
		ft_putchar('\0');
		val->k++;
		com++;
	}
	val->k += ft_putstr(com);
	free(com);
}
