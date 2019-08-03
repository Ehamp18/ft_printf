/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:27:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/02 22:26:34 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

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
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	return (ans);
}

static	void		printing(char *com, char c, t_flags *flags)
{
	if (flags->minus)
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

void				con_c(va_list options, t_flags *flags, t_val *val)
{
	char			*com;
	char			*tmp;
	char			c;

	tmp = ft_strnew(sizeof(char));
	com = ft_strnew(sizeof(char));
	c = ft_strcmp(flags->length, "l") == 0 ? va_arg(options, wint_t) :
		va_arg(options, int);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		FREE(((tmp = ft_strcpy(tmp, com))), com);
		com = wid_zer_min_c(flags->width, tmp, flags);
		printing(com, c, flags);
	}
	else
		ft_putchar(c);
	val->k += flags->width > 1 ? flags->width : 1;
	just_free(com, tmp);
}
