/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:28:18 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/06 03:43:49 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*retn;

	if (!(retn = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else if (!content)
	{
		retn->content = NULL;
		retn->content_size = 0;
	}
	else
	{
		if (!(retn->content = (size_t*)malloc(content_size)))
			return (NULL);
		ft_memcpy(retn->content, content, content_size);
		retn->content_size = content_size;
	}
	retn->next = NULL;
	return (retn);
}
