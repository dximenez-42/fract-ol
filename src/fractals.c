/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:12:08 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/09 00:16:23 by dximenez         ###   ########.fr       */
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

	i = -1;
	z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	c.r = z.r;
	c.i = z.i;
	while (++i < vars->iterations)
	{
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp + c.r;
		if ((z.r * z.r) + (z.i * z.i) > vars->escape)
		{
			color = map(i, vars->color, WHITE, vars->iterations);
			return (put_pixel(&vars->img, x, y, color));
		}
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

	i = -1;
	z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	c.r = vars->input.r;
	c.i = vars->input.i;
	while (++i < vars->iterations)
	{
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp + c.r;
		if ((z.r * z.r) + (z.i * z.i) > vars->escape)
		{
			color = map(i, vars->color, WHITE, vars->iterations);
			return (put_pixel(&vars->img, x, y, color));
		}
	}
	put_pixel(&vars->img, x, y, BLACK);
}

static void	calculate_pixel_burning_ship(int x, int y, t_vars *vars)
{
	int			i;
	int			color;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = -1;
	z.r = map(x, -3, +3, WINDOW_WIDTH) * (1 / vars->zoom) + vars->pos_x;
	z.i = map(y, +2, -2, WINDOW_HEIGHT) * (1 / vars->zoom) + vars->pos_y;
	c.r = z.r;
	c.i = z.i;
	while (++i < vars->iterations)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = -2 * z.r * z.i + c.i;
		z.r = tmp + c.r;
		if ((z.r * z.r) + (z.i * z.i) > vars->escape)
		{
			color = map(i, vars->color, WHITE, vars->iterations);
			return (put_pixel(&vars->img, x, y, color));
		}
	}
	put_pixel(&vars->img, x, y, BLACK);
}

void	render_fractal(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (vars->type == 'M')
				calculate_pixel_mandelbrot(x, y, vars);
			else if (vars->type == 'J')
				calculate_pixel_julia(x, y, vars);
			else if (vars->type == 'B')
				calculate_pixel_burning_ship(x, y, vars);
			++x;
		}
		++y;
	}
	image_to_window(vars);
}
