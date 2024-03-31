/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:43:27 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 17:07:53 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
int main()
{
	char *mem;

	mem = malloc(5 * sizeof(int));
	mem[0] = 'A';
	mem[1] = 'B';
	mem[2] = 'C';
	mem[3] = 'D';
	mem[4] = 'E';
	ft_bzero(mem, 5);
	printf("%c\n", mem[0]);
	printf("%c\n", mem[1]);
	printf("%c\n", mem[2]);
	printf("%c\n", mem[3]);
	printf("%c\n", mem[4]);
}

*/