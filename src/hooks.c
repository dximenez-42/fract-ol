/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:21 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/08 15:34:15 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	on_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, &vars->img.img);
	exit(0);
}

static int	keydown_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		on_destroy(vars);
	else if (keycode == 119)
		vars->pos_y += (0.5 * vars->zoom);
	else if (keycode == 97)
		vars->pos_x -= (0.5 * vars->zoom);
	else if (keycode == 100)
		vars->pos_x += (0.5 * vars->zoom);
	else if (keycode == 115)
		vars->pos_y -= (0.5 * vars->zoom);
	else if (keycode == 65362)
	{
		vars->iterations += 5;
		ft_printf("iterations: %d\n", vars->iterations);
	}
	else if (keycode == 65364)
	{
		vars->iterations -= 5;
		ft_printf("iterations: %d\n", vars->iterations);
	}
	render_fractal(vars);
	return (0);
}

static int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == Button5)
		vars->zoom *= 0.9;
	else if (keycode == Button4)
		vars->zoom *= 1.1;
	render_fractal(vars);
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, keydown_hook, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, on_destroy, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_hook, vars);
}
