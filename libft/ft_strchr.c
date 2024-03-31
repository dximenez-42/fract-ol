/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:39:14 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 18:56:59 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	char	*str;
	char	c;
	size_t	i;

	str = (char *)s;
	c = (char)ch;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

/*
int main()
{
	// printf("%s\n", strchr("abcde", 'a'));
	// printf("%s\n", strchr("abcde", 'd'));
	// printf("%s\n", strchr("abcde", 'e'));
	// printf("%s\n", strchr("abcde", '\0'));
	printf("%s\n", ft_strchr("teste", 'e'));
	printf("%s\n\n", strchr("teste", 'e'));

	printf("%d\n", memcmp(ft_strchr("teste", 'e'), strchr("teste", 'e'), 20));
}
*/