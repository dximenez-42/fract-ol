/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:51 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 19:22:16 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 == *s2 && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}

/*
int main()
{
	printf("%d:%d\n", memcmp("abcdef", "abcde", 5),
				   ft_memcmp("abcdef", "abcde", 5) );

	printf("%d:%d\n", memcmp("abc", "abc", 7),
				   ft_memcmp("abc", "abc", 7) );

	printf("%d:%d\n", memcmp("atoms\0\0\0\0", "atoms\0abc", 8),
				   ft_memcmp("atoms\0\0\0\0", "atoms\0abc", 8) );
}

*/