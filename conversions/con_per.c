/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:42:18 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/03 20:25:11 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static char			*wzm_help(int wid, char *ans, t_flags *fl, int i)
{
	int				h;

	while (wid >= 0 && !fl->minus && fl->width)
	{
		ans[wid] = ' ';
		wid--;
	}
	wid = i;
	h = ft_strlen(ans);
	while (i-- >= 0 && fl->minus)
		ans[h++] = ' ';
	if (!fl->minus && fl->zero)
	{
		while (ans[wid] == ' ')
		{
			ans[wid] = '0';
			wid--;
		}
	}
	return (ans);
}

static char			*wid_zer_min(int wid, char *s, t_flags *fl)
{
	int				i;
	char			*ans;

	if (wid <= (int)ft_strlen(s))
		return (ft_strdup(s));
	i = ft_strlen(s);
	ans = ft_strnew(wid);
	wid--;
	if (fl->width && !fl->minus)
	{
		ans[wid] = s[0];
		wid--;
	}
	else if (fl->minus)
	{
		ans[0] = s[0];
		wid--;
	}
	wzm_help(wid, ans, fl, i);
	return (ans);
}

void				con_per(t_flags *fl, t_val *val)
{
	char			*com;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	com = (char*)ft_memalloc(sizeof(fl));
	*com = '%';
	if (fl->width)
	{
		tmp = ft_strcpy(tmp, com);
		free(com);
		com = wid_zer_min(fl->width, tmp, fl);
	}
	val->k += ft_putstr(com);
	free(com);
	free(tmp);
}
