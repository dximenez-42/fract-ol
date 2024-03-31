/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:30:14 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 19:20:26 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char	*str;
	char	c;
	size_t	i;

	str = (char *)s;
	c = (char)ch;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}

/*
int main()
{
	const char *str = "hola que tal";
	char *res = ft_strrchr(str, 's');
	printf("%s\n", res);		// NULL
}
*/

/*
int main()
{
	char *str = "hola que tal";
	printf("%s\n", ft_strrchr(str + 2, 'h'));		// NULL
}
*/

/*
int main()
{
	char *str = "";
	printf("%s\n", ft_strrchr(str, '\0'));		// \0
}
*/