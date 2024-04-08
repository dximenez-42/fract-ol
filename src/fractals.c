/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:12:08 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/08 22:47:52 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculate_pixel_mandelbrot(int x, int y, t_vars *vars)
{
	int			i;
	int			color;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	c.r = z.r;
	c.i = z.i;
	while (i < vars->iterations)
	{
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp + c.r;
		if ((z.r * z.r) + (z.i * z.i) > vars->escape)
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
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	c.r = vars->julia.r;
	c.i = vars->julia.i;
	while (i < vars->iterations)
	{
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp + c.r;
		if ((z.r * z.r) + (z.i * z.i) > vars->escape)
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
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (vars->type == 'M')
				calculate_pixel_mandelbrot(x, y, vars);
			else
				calculate_pixel_julia(x, y, vars);
			++x;
		}
		++y;
	}
	image_to_window(vars);
}
