/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:12 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 16:18:35 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_square(t_data *data, int x, int y, int color, int size_x, int size_y)
{
	for (size_t i = x; i < x + size_x; i++)
	{
		for (size_t j = y; j < y + size_y; j++)
		{
			my_mlx_pixel_put(data, i, j, color);
		}
	}
}

void	make_circle(t_data *data, int x, int y, int color, int radius)
{
	double i, angle, x1, y1;

	for(i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = radius * cos(angle * M_PI / 180);
		y1 = radius * sin(angle * M_PI / 180);
		my_mlx_pixel_put(data, (int)x + x1, (int)y + y1, color);
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	fractol_close(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	make_square(&img, 500, 250, create_trgb(0, 0, 255, 0), 200, 200);
	make_circle(&img, 100, 100, 0x00FF0000, 50);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, fractol_close, &vars);
	mlx_loop(vars.mlx);
}