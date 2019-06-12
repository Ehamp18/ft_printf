#include "inclu/ft_printf.h"

static char			*width_f(int wid, char *s, t_flags *flags)
{
	int				i;
	char			*ans;
	int				j;
	int				k;
	int				h;

	j = 0;
	k = 0;
	ans = ft_strnew(ft_numlen(wid));
	(flags->minus == 1) ? (i = 0) : (i = ft_strlen(s));
	if (!wid)
		return (s);
	if (wid <  ft_strlen(s))
		return (s);
	while (s[i])
	{
		ans[i] = s[i];
		
	}
	if (flags->width == 1)
	{
		while ((wid > 0))
		{
			ans[wid] = (' ');
			wid--;
		}
	}
	if (flags->minus == 1)
	{
		while (j)
		{
			ans[k] = ' ';
			j--;
			k++;
		}
	}
	if (flags->zero == 1)
	{
		h = ft_strlen(ans) - 1;
		while ((ft_isdigit(ans[h]) == 1) || (ans[h] == '-'))
			h--;
		while (ans[h])
		{
			ans[h] = '0';
			h--;
		}
	}
	return (ans);
}