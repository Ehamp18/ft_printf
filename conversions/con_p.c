/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:30 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 00:36:49 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*precision_p(int perc, char *point)
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

static void			wzm_help(int wid, char *ans, t_flags *flag)
{
	int				h;

	while (wid > 0 && flag->minus == 0 && flag->width >= 1)
	{
		wid--;
		ans[wid] = ' ';
	}
	h = ft_strlen(ans);
	while (wid > 0 && flag->minus == 1)
	{
		wid--;
		ans[h++] = ' ';
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

	if (wid < (int)ft_strlen(s))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	j = -1;
	i = flag->minus == 1 ? 0 : ft_strlen(s);
	if (flag->minus == 1)
	{
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 1 || ft_isalpha(s[i]))
			{
				ans[++j] = s[i];
				wid--;
			}
			i++;
		}
	}
	else
		while (i > 0)
		{
			if (ft_isdigit(s[i]) == 1 || ft_isalpha(s[i]))
			{
				ans[++j] = s[i];
				wid--;
			}
			i--;
		}
	wzm_help(wid, ans, flag);
	return (ans);
}

void				con_p(va_list options, t_flags *flags, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = ft_itoa_u_p(va_arg(options, intptr_t));
	if (flags->precis > 0)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = precision_p(flags->precis, tmp);
	}
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_p(flags->width, tmp, flags);
	}
	com = ft_ccstrjoini('0', 'x', com);
	val->k += ft_putstr(com);
	just_free(com, tmp);
}
