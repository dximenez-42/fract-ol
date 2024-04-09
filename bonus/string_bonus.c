/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:32:52 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/09 23:02:06 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

double	atod(char *s)
{
	long	num;
	double	dec;
	double	power;
	int		sign;

	num = 0;
	dec = 0;
	power = 0.1;
	sign = 1;
	while (is_space(*s))
		++s;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s != '.' && *s != '\0')
		num = num * 10 + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s != '\0')
	{
		dec = dec + (*s++ - '0') * power;
		power /= 10;
	}
	return ((num + dec) * sign);
}

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
