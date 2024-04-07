/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:12:08 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/07 17:07:58 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculate_pixel(int x, int y, t_vars *vars)
{
	int	i;
	int	color;
	
	i = 0;
	vars->c.r = map(x, -2, 2, 0, WINDOW_WIDTH);
	vars->c.i = map(y, 2, -2, 0, WINDOW_HEIGHT);
	while (i < vars->iterations)
	{
		vars->z = sum_complex(square_complex(vars->z), vars->c);

		//TODO set a color
		if ((vars->z.r * vars->z.r) + (vars->z.i * vars->z.i) > vars->escape)
		{
			color = map(i, BLACK, WHITE, 0, vars->iterations);
			put_pixel(&vars->img, x, y, color);
			return ;
		}
		++i;
	}
	put_pixel(&vars->img, x, y, PURPLE);
}

void	mandelbrot(t_vars *vars)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			calculate_pixel(x, y, vars);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, &vars->img, 0, 0);
}