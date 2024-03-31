/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:47:18 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 18:17:14 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	size_t	i;

	i = 0;
	current = lst;
	while (current != 0)
	{
		current = current->next;
		++i;
	}
	return (i);
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