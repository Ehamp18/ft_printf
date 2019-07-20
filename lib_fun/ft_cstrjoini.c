/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrjoini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 02:10:40 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/19 15:45:05 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_cstrjoini(char s1, char *s2, t_flags *flag)
{
	char		*str;
	size_t		len;
	int			i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s2) + 1;
	if (!(str = ft_strnew(len)))
		return (0);
	while (*s2 == ' ' && *s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	if (flag->plus && flag->width && i)
		i--;
	str[i] = s1;
	ft_strcat(str, s2);
	return (str);
}
