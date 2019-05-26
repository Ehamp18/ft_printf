/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:09:30 by elhampto          #+#    #+#             */
/*   Updated: 2019/05/24 21:37:43 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	// {'f', &con_f}
};

/*
** Width
** -- min-width: is the total width, if width is smaller than min width,
** -- its filled with empty spaces: s, c, p, X, x, o, u, d
*/

char			*width(int wid, char *s)
{
	int			i;
	char		*ans;

	ans = ft_strnew(ft_numlen(wid));
	ft_memset(ans, '0', ft_strlen(ans));
	i = ft_strlen(s);
	if (!wid)
		return (0);
	if (wid < i)
		return (0);
	i -= 1;
	while ((wid > i) && s[i])
	{
		ans[i] = s[i];
		i--;
	}
	while ((wid > 0))
	{
		ans[i] = (' ');
		wid--;
		i--;
	}
	return (ans);
}

/*
** Precision
** -- precision: if it is zero or less it is ignored, if it's bigger than the
** -- string it's ignored: s
**
** Precision is always after a "."
**
** ** Declare the function(with paramitors)
** ** -- IF the value that is given is 0 or less, then nothing happens
** ** -- IF the value is greater then the string then nothing happens
** ** -- IF the value is above 0 and is lower then the string count, then print
** ** -- - ,characters, up to the number that is specified for the precision.
*/

//  char			precision(int perc, char *point)
//  {
//  	int			i;

// i = 0;
// ERROR(!perc || !point);
// ZERO(perc < (int)ft_strlen(point));
// while (point[i] && point[i] != '.')
// 	i++;
// while (point[i] && point[i])

// 	return ();
// }

/*
** ||
** -- precision: if precision is smaller than the length of the number it is
** -- ignored, but if it is bigger it is filled with 0's: d, u, o, x, X,
**
** ** -- Declare the function(with paramitors)
** ** -- -- IF precision is smaller then the length, nothing happens.
** ** -- -- IF precision is greater then the length, then 0 are printed for the
** ** -- -- - rest of the spaces given.
**
**  +,  -,  '',  '0'
**
**  d, u, o, x, X:   ll-long long,  l-long,  hh-char,  h-short
**
**  s, p: 2nd flags ignore all
**
**  c: l-'wint_t'
*/

/*
** '-' : (minus)	Left-align the output of this placeholder. (The default is
** -- to right-align the output.)
*/

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
	while (j >= 0)
	{
		res[j] = m[0];
		j--;
	}
	res[j] = '\0';
	return (res);
}

/*
** '+' : (plus)	Prepends a plus for positive signed-numeric types. positive = +,
** -- negative = -.
** -- (The default doesn't prepend anything in front of positive numbers.)
*/

char			*plus_flag(char *a)
{
	char		*s;
	char		*res;

	s = ft_strnew(ft_strlen(a));
	if (a[0] != '-')
	{
		*s = '+';
		res = ft_strjoin(s, a);
		return (res);
	}
	*s = '-';
	s++;
	res = ft_strjoin(s, a);
	return (res);
}

/*
** ' ' : (space)	Prepends a space for positive signed-numeric types. positive
** -- =  , negative = -. This flag is ignored if the + flag exists.
** -- (The default doesn't prepend anything in front of positive numbers.)
*/

char			*space_flag(char *a)
{
	char		*s;
	char		*res;

	s = ft_strnew(ft_strlen(a));
	if (a[0] != '-')
	{
		*s = ' ';
		res = ft_strjoin(s, a);
		return (res);
	}
	*s = '-';
	s++;
	res = ft_strjoin(s, a);
	return (res);
}

/*
** '0' : (zero)	When the 'width' option is specified, prepends zeros for numeric
** -- types. (The default prepends spaces.)
** -- For example, printf("%2X",3) produces  3, while printf("%04X",3) produces
** -- in 0003.
*/

char			*zero_flag(char *a)
{
	int			i;

	i = ft_strlen(a) - 1;
	while (a[i] == ((ft_isdigit(a[i])) == 1))
		i--;
	while ((a[i] == ((ft_isdigit(a[i])) != 1)) && a[i])
	{
		a[i] = '0';
		i--;
	}
	return (a);
}

/*
** '#' : (hash)	Alternate form:
** -- For g and G types, trailing zeros are not removed.
** -- For f, F, e, E, g, G types, the output always contains a decimal point.
** -- For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to
** -- non-zero numbers.
*/

/*
** h
** hh
*/

/*
** l
*/

char			*l_flag(long k)
{
	char		*l;

	l = ft_itoa_long(k);
	return (l);
}

/*
** ll
*/

/*
** + - ' ' 0 #
** 1 0  0  0 0
*/
