/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:23:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/04 02:37:19 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

static void		fl_1(const char *str, t_flags *fl)
{
	while (str[fl->check] == '-' || str[fl->check] == '+' ||
		str[fl->check] == '0' || str[fl->check] == ' ' || str[fl->check] == '#')
	{
		if (str[fl->check] == '-')
			INC((fl->minus = 1), fl->check);
		if (str[fl->check] == '+')
			INC((fl->plus = 1), fl->check);
		if (str[fl->check] == '0')
			INC((fl->zero = 1), fl->check);
		if (str[fl->check] == ' ')
			INC((fl->space = 1), fl->check);
		if (str[fl->check] == '#')
			INC((fl->hash = 1), fl->check);
	}
}

static void		op_ch(const char *str, t_flags *fl, int cur, va_list options)
{
	char		*l;
	int			j;

	j = 0;
	l = ft_strnew(ft_strlen(str));
	if (str[fl->check] == '.' && str[cur] == '*')
	{
		fl->precis = va_arg(options, int);
		fl->check += 2;
	}
	else if (str[fl->check] == '.')
	{
		while (str[fl->check] == '.' && ft_isdigit(str[cur]))
			INC((l[j] = str[cur++]), j);
		fl->precis = j > 0 ? ft_atoi(l) : -1;
		fl->check += ++j;
	}
	free(l);
}

static void		fl_2_length(const char *str, t_flags *fl, int cur)
{
	if (str[fl->check] == 'l' || str[fl->check] == 'h')
	{
		if (str[fl->check] == 'l' && str[cur] == 'l')
		{
			INC((fl->length = 216), fl->check);
		}
		else if (str[fl->check] == 'h' && str[cur] == 'h')
			fl->check++;
		else if (str[fl->check] == 'l')
			fl->length = 108;
		fl->check++;
	}
}

static void		fl_2(const char *str, t_flags *fl, va_list options)
{
	int			cur;
	char		*l;
	int			j;

	cur = fl->check;
	j = 0;
	if (ft_isdigit(str[fl->check]) || str[fl->check] == '*')
	{
		l = ft_strnew(ft_strlen(str));
		if (str[fl->check] == '*')
		{
			INC((fl->width = va_arg(options, int)), fl->check);
		}
		else if (ft_isdigit(str[fl->check]))
		{
			while (ft_isdigit(str[cur]) == 1)
				INC((l[j] = str[cur++]), j);
			fl->width = ft_atoi(l);
			fl->check += j;
		}
		free(l);
	}
	cur = fl->check + 1;
	op_ch(str, fl, cur, options);
	fl_2_length(str, fl, cur);
}

int				checks(va_list options, const char *str, t_val *val)
{
	t_flags		fl;
	int			i;
	int			k;

	i = 0;
	ft_bzero(&fl, sizeof(t_flags));
	fl.check = 1;
	while (*str == '%' && str[fl.check] && str[fl.check] != '\n')
	{
		k = fl.check;
		fl_1(str, &fl);
		fl_2(str, &fl, options);
		if (str[fl.check] == '%')
		{
			con_per(&fl, val);
			break ;
		}
		if (str[fl.check] == g_conver_check[i].op)
		{
			g_conver_check[i].kl(options, &fl, val);
			break ;
		}
		i += k == fl.check ? 1 : 0;
	}
	return (fl.check);
}
