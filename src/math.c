/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:24:45 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/07 16:54:22 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
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