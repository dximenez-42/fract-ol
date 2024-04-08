/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:12:08 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/08 19:31:15 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculate_pixel_mandelbrot(int x, int y, t_vars *vars)
{
	int			i;
	int			color;
	double		tmp;

	i = 0;
	vars->z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	vars->z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	vars->c.r = vars->z.r;
	vars->c.i = vars->z.i;
	while (i < vars->iterations)
	{
		tmp = (vars->z.r * vars->z.r) - (vars->z.i * vars->z.i);
		vars->z.i = 2 * vars->z.r * vars->z.i + vars->c.i;
		vars->z.r = tmp + vars->c.r;
		if ((vars->z.r * vars->z.r) + (vars->z.i * vars->z.i) > vars->escape)
		{
			color = map(i, PSYCHO, WHITE, vars->iterations);
			put_pixel(&vars->img, x, y, color);
			return ;
		}
		++i;
	}
	put_pixel(&vars->img, x, y, BLACK);
}

static void	calculate_pixel_julia(int x, int y, t_vars *vars)
{
	int			i;
	int			color;
	double		tmp;

	i = 0;
	vars->z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	vars->z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	vars->c.r = vars->julia.r;
	vars->c.i = vars->julia.i;
	while (i < vars->iterations)
	{
		tmp = (vars->z.r * vars->z.r) - (vars->z.i * vars->z.i);
		vars->z.i = 2 * vars->z.r * vars->z.i + vars->c.i;
		vars->z.r = tmp + vars->c.r;
		if ((vars->z.r * vars->z.r) + (vars->z.i * vars->z.i) > vars->escape)
		{
			color = map(i, PSYCHO, WHITE, vars->iterations);
			put_pixel(&vars->img, x, y, color);
			return ;
		}
		++i;
	}
	put_pixel(&vars->img, x, y, BLACK);
}

void	render_fractal(t_vars *vars)
{
	int	x;
	int	y;

	// mlx_clear_window(vars->mlx, vars->win);		//TODO comprobar optimizacion
	#pragma omp parallel
	{
		t_vars local_vars = *vars;
		#pragma omp for
		for (y = 0; y < WINDOW_HEIGHT; ++y)
		{
			for (x = 0; x < WINDOW_WIDTH; ++x)
			{
				if (vars->type == 'M')
					calculate_pixel_mandelbrot(x, y, &local_vars);
				else
					calculate_pixel_julia(x, y, &local_vars);
			}
		}
	}
	image_to_window(vars);
}
