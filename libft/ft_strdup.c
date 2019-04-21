/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:35:59 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/18 09:38:36 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	int				i;
	char			*str;

	i = 0;
	if (!(str = ((char*)malloc(sizeof(char) * (ft_strlen(s1) + 1)))))
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
