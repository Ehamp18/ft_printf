/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 00:28:30 by elhampto          #+#    #+#             */
/*   Updated: 2019/06/10 15:22:00 by elhampto         ###   ########.fr       */
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

static char			*width_p(int wid, char *s)
{
	int				i;
	char			*ans;

	ans = ft_strnew(wid);
	i = ft_strlen(s);
	if (wid < i)
		return (s);
	// wid -= i;
	while (i >= 0)
	{
		ans[i] = s[i];
		i--;
	}
	while ((wid > 0))
	{
		ans[wid] = (' ');
		wid--;
	}
	return (ans);
}


static char			*zero_flag_p(char *a)
{
	int				i;

	i = ft_strlen(a) - 1;
	while ((ft_isdigit(a[i]) == 1) || (a[i] == '-'))
		i--;
	while ((ft_is_space(a[i]) == 1) && a[i])
	{
		a[i] = '0';
		i--;
	}
	return (a);
}

static char			*minus_flag_p(char *m)
{
	int				j;
	int				i;
	char			*res;

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

void				con_p(va_list options, t_flags *flags, t_val *val)
{
	intptr_t		a;
	char			*com;

	a = va_arg(options, intptr_t);
	com = ft_itoa_u_p(a);
	if (flags->precis > 0)
		com = precision_p(flags->precis, com);
	if (flags->width > 0)
		com = width_p(flags->width, com);
	if (flags->zero == 1)
		com = zero_flag_p(com);
	if (flags->minus == 1)
		com = minus_flag_p(com);
	val->k += ft_putstr("0x");
	val->k += ft_putstr(com);
}
