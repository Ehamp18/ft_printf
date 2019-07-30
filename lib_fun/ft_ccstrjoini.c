/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccstrjoini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:33:46 by elhampto          #+#    #+#             */
/*   Updated: 2019/07/29 22:14:02 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclu/ft_printf.h"

char			*ft_ccstrjoini(char s1, char s2, char *s3, t_flags *flag)
{
	char		*str;
	int			i;

	i = 0;
	RETY(!s1 || !s2, NULL);
	ZERO(!(str = ft_strnew(ft_strlen(s3))));
	while (*s3 == ' ' && *s3)
	{
		str[i] = *s3++;
		i++;
	}
	if (flag->width && flag->minus)
		flag->si = 1;
	// 	s3[ft_strlen(s3) - 1] = '\0';
	// if (flag->zero)
	// 	s2++;
	str[i] = s1;
	i++;
	str[i] = s2;
	ft_strcat(str, s3);
	return (str);
}
