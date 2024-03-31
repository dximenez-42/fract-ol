/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:43:57 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/01 19:48:30 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	first = 0;
	while (lst != 0)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == 0)
		{
			ft_lstclear(&first, del);
			return (first);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	new->next = 0;
	return (first);
}
