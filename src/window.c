/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:36:50 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 17:23:05 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	image_to_window(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	init_window(t_vars *vars, t_data *img, int h, int w)
{
	vars->mouse_x = 0;
	vars->mouse_y = 0;
	vars->height = h;
	vars->width = w;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->height, vars->width, TITLE);
	img->img = mlx_new_image(vars->mlx, vars->height, vars->width);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}