/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 18:31:21 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static void			wzm_help(int wid, char *ans, t_flags *flag)
{
	int				h;

	while (wid > 0 && !flag->minus && flag->width)
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
	while ((ft_isdigit(ans[h]) || ans[h] == '-') && flag->zero)
		h--;
	while (ans[h] && flag->zero)
	{
		ans[h] = '0';
		h--;
	}
}

static char			*wid_zer_min_c(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	if (wid-- < ((int)ft_strlen(s) - 1))
		return (ft_strdup(s));
	ans = ft_strnew(wid);
	i = flag->minus == 1 ? -1 : ft_strlen(s);
	if (flag->minus)
	{
		while (s[++i])
		{
			ans[i] = s[i];
			wid--;
		}
	}
	else
		while (i--)
		{
			ans[wid] = s[i];
			wid--;
		}
	wzm_help(wid, ans, flag);
	return (ans);
}

static	void		printing(char *com, char c, t_flags *fl)
{
	if (fl->minus)
	{
		ft_putchar(c);
		ft_putstr(com);
	}
	else
	{
		ft_putstr(com);
		ft_putchar(c);
	}
}

void				con_c(va_list options, t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;
	char			c;

	tmp = ft_strnew(sizeof(char));
	com = ft_strnew(sizeof(char));
	c = fl->length == 108 ? va_arg(options, wint_t) : va_arg(options, int);
	if (fl->width)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_c(fl->width, tmp, fl);
		printing(com, c, fl);
	}
	else
		ft_putchar(c);
	val->k += fl->width > 1 ? fl->width : 1;
	just_free(com, tmp);
}
