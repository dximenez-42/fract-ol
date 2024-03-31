/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:09:24 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/26 15:19:47 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		++s;
	}
}

/*
int main()
{
	ft_putstr_fd("HOLA", 1);
}
*/