/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:09:22 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 18:03:22 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
int main()
{
	t_list *list = ft_lstnew("test1");
	list->next = ft_lstnew("test2");

	t_list *new = ft_lstnew("new");
	ft_lstadd_back(&list, new);
	printf("%d\n", ft_lstsize(list));
}
*/