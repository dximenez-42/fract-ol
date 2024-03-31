/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:14:37 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 18:40:39 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Scans the initial n bytes
 * both c and the bytes of s are interpreted as unsigned char
*/
void	*ft_memchr(const void *s, int ch, size_t n)
{
	unsigned char	*str;
	unsigned char	c;
	size_t			i;

	str = (unsigned char *)s;
	c = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	return (0);
}

/*
int main()
{
	printf("%s\n", (char *)ft_memchr("abcde\0", 'c', 6));
	printf("%s\n", (char *)ft_memchr("abcde\0", 'a', 6));
	printf("%s\n", (char *)ft_memchr("abcde\0", '\0', 6));
}
*/