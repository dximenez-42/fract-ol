/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:12 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 17:23:54 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_square(t_data *img, int x, int y, int color, int size_x, int size_y)
{
	for (size_t i = x; i < x + size_x; i++)
	{
		for (size_t j = y; j < y + size_y; j++)
		{
			put_pixel(img, i, j, color);
		}
	}
}


int	main(void)
{
	t_vars	vars;

	init_window(&vars, &vars.img, 1280, 720);
	make_square(&vars.img, vars.height / 2 - 100, vars.width / 2 - 100, create_trgb(0, 0, 255, 0), 200, 200);
	image_to_window(&vars, 0, 0);
	make_square(&vars.img, vars.height - 200 , vars.width - 200, create_trgb(0, 0, 0, 255), 200, 200);
	image_to_window(&vars, 0, 0);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
}