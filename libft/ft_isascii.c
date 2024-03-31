/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:43:43 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 19:22:05 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int main()
{
	char string[] = "0123456789ABCdefGHIjklMNOpqr
		STUvwxYZ!@#$%^&*()_+{}[]ñáéíóúñàèìòù";
	int i = 0;
	while (string[i] != '\0')
	{
		printf("%c > %d %d\n", string[i],
			isascii(string[i]), ft_isascii(string[i]));
		i++;
	}
}
*/