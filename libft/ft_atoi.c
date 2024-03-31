/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:42:26 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 19:21:51 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	size_t	i;
	int		v;
	int		sy;

	i = 0;
	v = 0;
	sy = 1;
	while (is_space(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sy = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		v = (v * 10) + (s[i] - '0');
		i++;
	}
	return (sy * v);
}

/*
int main()
{
	printf("1, %d = %d\n", ft_atoi("0"), atoi("0"));
	printf("2, %d = %d\n", ft_atoi("42"), atoi("42"));
	printf("3, %d = %d\n", ft_atoi("4 2"), atoi("4 2"));
	printf("4, %d = %d\n", ft_atoi("-42"), atoi("-42"));
	printf("5, %d = %d\n", ft_atoi("--42"), atoi("--42"));
	printf("6, %d = %d\n", ft_atoi("+42"), atoi("+42"));
	printf("7, %d = %d\n", ft_atoi("++42"), atoi("++42"));
	printf("8, %d = %d\n", ft_atoi("42hola"), atoi("42hola"));
	printf("9, %d = %d\n", ft_atoi("4hola2"), atoi("4hola2"));
	printf("10, %d = %d\n", ft_atoi("hola42"), atoi("hola42"));

	// printf("%d = 42\n", ft_atoi("42"));
	// printf("%d = -42\n", ft_atoi("-42"));
	// printf("%d = 0\n", ft_atoi("--42"));
	// printf("%d = 42\n", ft_atoi("+42"));
	// printf("%d = 0\n", ft_atoi("++42"));
}
*/