/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:43:59 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 18:57:17 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	size_t	i;

	mem = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (mem == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		mem[i] = s[i];
		++i;
	}
	mem[i] = '\0';
	return (mem);
}

/*
int main()
{
	char *s = strdup("Hola");

	printf("%s\n", s);
}
*/