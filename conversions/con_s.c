/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/23 19:29:00 by elhampto         ###   ########.fr       */
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
	point = res;
	return (point);
}

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

static char			*wid_zer_min_s(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	wid--;
	if (wid < (int)ft_strlen(s))
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
	return (ans);
}

void				con_s(va_list options, t_flags *flags, t_val *val)
{
	wchar_t			*a;
	char			*com;
	char			*tmp;

	a = 0;
	com = ft_strnew(sizeof(char));
	tmp = ft_strnew(sizeof(char));
	if (ft_strcmp(flags->length, "l") == 0)
		a = va_arg(options, wchar_t*);
	else
		com = va_arg(options, char*);
	if (a)
		com = (char*)a;
	if (com == NULL)
		com = "(null)";
	if (flags->precis > 0 || flags->precis == -1)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = precision_s(flags->precis, tmp);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = wid_zer_min_s(flags->width, tmp, flags);
	}
	val->k += ft_putstr(com);
	free(tmp);
}
