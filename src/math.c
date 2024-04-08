/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:24:45 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/08 15:27:06 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double num, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (num - 0) / (o_max - 0) + n_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.r = z1.r + z2.r;
	res.i = z1.i + z2.i;
	return (res);
}

/**
 * r = (r^2 - i^2)
 * i = (2 * x * y)
*/
t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.r = (z.r * z.r) - (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}
