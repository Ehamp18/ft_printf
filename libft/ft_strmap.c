/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:35:03 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/26 20:33:46 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*sh;
	int				i;

	i = 0;
	if (!s || !f || !*s)
		return (NULL);
	if (!(sh = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		sh[i] = f(s[i]);
		i++;
	}
	return (sh);
}
