/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:43:50 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 19:22:12 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
int main()
{
	char string[] = "0123456789ABCdefGHIjklMNOpqrSTUvwxYZ\t\v\r";
	int i = 0;
	while (string[i] != '\0')
	{
		printf("%c > %d %d\n", string[i],
			isprint(string[i]), ft_isprint(string[i]));
		i++;
	}
}
*/