/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:16:08 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/31 20:39:39 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**word_check(char **arc, const char *s, int word, char c)
{
	int				a;
	int				b;
	int				d;

	b = 0;
	while (word)
	{
		if (s[b] && s[b] != c)
			a = b;
		while (s[b] && s[b++] != c)
			if (s[b] == '\0' || s[b] == c)
			{
				d = b - a;
				if (!(*arc++ = ft_strsub(s, a, d)))
					return (NULL);
				word--;
			}
	}
	return (arc);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**arr;
	int				word;

	if (!s || !c)
		return (0);
	word = ft_wordcount(s, c);
	if (!(arr = (char**)ft_memalloc(sizeof(char*) * (word + 1))))
		return (0);
	word_check(arr, s, word, c);
	return (arr);
}
