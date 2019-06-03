/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:09:30 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/02 11:57:39 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

t_check	g_conver_check[] =
{
	{'d', &con_d},
	{'i', &con_i},
	{'c', &con_c},
	{'s', &con_s},
	{'x', &con_x},
	{'X', &con_xa},
	{'p', &con_p},
	{'o', &con_o},
	{'u', &con_u},
	{'f', &con_f}
};

char			*width(int wid, char *s)
{
	int			i;
	char		*ans;
	int			j;

	ans = ft_strnew(ft_numlen(wid));
	j = ft_numlen(wid);
	i = ft_strlen(s);
	if (!wid)
		return (s);
	if (wid < i)
		return (s);
	wid -= i;
	while (i >= 0)
	{
		ans[j] = s[i];
		i--;
		j--;
	}
	while ((wid > 0))
	{
		ans[j] = (' ');
		wid--;
		j--;
	}
	return (ans);
}

char			*precision(int perc, char *point)
{
	int			i;
	char		*res;
	int			j;

	res = ft_strnew(ft_numlen(perc));
	j = ft_numlen(perc);
	i = ft_strlen(point);
	if (!perc)
		return (point);
	if (perc < (int)ft_strlen(point))
		return (point);
	perc -= i;
	while (i >= 0)
	{
		res[j] = point[i];
		i--;
		j--;
	}
	while ((perc > 0))
	{
		res[j] = ('0');
		perc--;
		j--;
	}
	return (res);
}

char			*minus_flag(char *m)
{
	int			j;
	int			i;
	char		*res;

	j = 0;
	i = 0;
	res = ft_strnew(ft_strlen(m));
	while (ft_is_space(*m) == 1)
	{
		j++;
		m++;
	}
	while (*m)
	{
		res[i] = *m;
		m++;
		i++;
	}
	while (j)
	{
		res[i] = ' ';
		j--;
		i++;
	}
	return (res);
}

char			*plus_flag(char *a, int i)
{
	char		*s;
	char		*res;
	int			j;

	j = 0;
	s = ft_strnew(ft_strlen(a));
	while (ft_isdigit(*a) == 0)
	{
		if (a[j] == '-')
		{
			a++;
			*s = '-';
			res = ft_strjoin(s, a);
			return (res);
		}
		a++;
	}
	if (i == 1)
	{
		a++;
		*s = '-';
		res = ft_strjoin(s, a);
		return (res);
	}
	a++;
	*s = '+';
	res = ft_strjoin(s, a);
	return (res);
}
