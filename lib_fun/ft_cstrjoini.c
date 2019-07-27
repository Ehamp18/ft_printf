/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrjoini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 02:10:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/26 16:01:56 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_cstrjoini(char s1, char *s2, t_flags *flag)
{
	char		*str;
	size_t		len;
	int			i;

	i = 0;
	RETY(!s1 || !s2, NULL);
	len = ft_strlen(s2) + 1;
	ZERO(!(str = ft_strnew(len)));
	if (s1 == ' ' && *s2 == ' ')
		return (ft_strdup(s2));
	while (*s2 == ' ' && *s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	if (flag->width && flag->minus)
		s2[ft_strlen(s2) - 1] = '\0';
	if (flag->plus && flag->width && i)
		i--;
	if (flag->zero)
		s2++;
	str[i] = s1;
	ft_strcat(str, s2);
	return (str);
}
