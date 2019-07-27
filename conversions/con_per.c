/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:42:18 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/25 14:57:53 by elhampto         ###   ########.fr       */
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
	wid = i;
	h = ft_strlen(ans);
	while (i-- >= 0 && flag->minus == 1)
		ans[h++] = ' ';
	if (flag->minus == 0 && flag->zero == 1)
	{
		while (ans[wid] == ' ')
		{
			ans[wid] = '0';
			wid--;
		}
	}
	return (ans);
}

static char			*wid_zer_min(int wid, char *s, t_flags *flag)
{
	int				i;
	char			*ans;

	if (wid <= (int)ft_strlen(s))
		return (ft_strdup(s));
	i = ft_strlen(s);
	ans = ft_strnew(wid);
	wid--;
	if (flag->width >= 1 && flag->minus == 0)
	{
		ans[wid] = s[0];
		wid--;
	}
	else if (flag->minus == 1)
	{
		ans[0] = s[0];
		wid--;
	}
	i = wid;
	ans = wzm_help(wid, ans, flag, i);
	return (ans);
}

int					con_per(t_flags *flags, t_val *val)
{
	char			*com;
	char			*tmp;
	int				i;

	tmp = ft_strnew(sizeof(char));
	com = (char*)ft_memalloc(sizeof(flags));
	*com = '%';
	i = ft_strlen(com);
	if (flags->width >= 1 || flags->minus == 1 || flags->zero == 1)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = wid_zer_min(flags->width, tmp, flags);
	}
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
	return (i);
}
