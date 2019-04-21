/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:36:07 by elhampto          #+#    #+#             */
/*   Updated: 2019/03/27 14:33:18 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*sf;
	t_list	*head;

	if (!lst)
		return (NULL);
	if (!(sf = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	sf = f(lst);
	head = sf;
	while (lst->next)
	{
		lst = lst->next;
		sf->next = f(lst);
		sf = sf->next;
	}
	return (head);
}
