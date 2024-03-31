/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:36:54 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/11 18:12:46 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * function shall compare not more than n bytes
 * (bytes that follow a NUL character are not compared)
 * s1 -> s2
 * return: difference of the first pair of bytes that are found different
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main()
{
	char *s1 = "hola";
	char *s2 = "";
	int num = 0;
	// printf("%d\n", ft_strncmp(s1, s2, num));
	// printf("%d\n", strncmp(s1, s2, num));

	printf("%d\n", strncmp("b", "a", 0));
}
*/