/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:16:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/31 19:47:22 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	size_t			sta;
	size_t			end;
	char			*string;

	if (!s)
		return (NULL);
	sta = 0;
	end = ft_strlen(s) - 1;
	while (s[sta] && (s[sta] == ' ' || s[sta] == '\t' || s[sta] == '\n'))
		sta++;
	while (end && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (end <= sta)
		return (ft_strnew(0));
	if (!(string = ft_strnew(end - sta + 1)))
		return (NULL);
	ft_strncpy(string, s + sta, end - sta + 1);
	string[end - sta + 1] = '\0';
	return (string);
}
