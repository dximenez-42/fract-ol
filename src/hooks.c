/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:21 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/09 22:52:01 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_view(t_vars *vars)
{
	vars->zoom = 1.0;
	vars->pos_x = 0;
	vars->pos_y = 0;
}

static int	on_destroy(t_vars *vars)
{
	if (vars == NULL)
		exit(0);
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}

static int	keydown_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		on_destroy(vars);
	else if (keycode == 119)
		vars->pos_y += (0.5 * (1 / vars->zoom));
	else if (keycode == 97)
		vars->pos_x -= (0.5 * (1 / vars->zoom));
	else if (keycode == 100)
		vars->pos_x += (0.5 * (1 / vars->zoom));
	else if (keycode == 115)
		vars->pos_y -= (0.5 * (1 / vars->zoom));
	else if (keycode == 32)
		reset_view(vars);
	else if (keycode == 65362 || keycode == 65364)
	{
		vars->iterations += 65363 - keycode;
		ft_printf("Iterations: %d\n", vars->iterations);
	}
	else if (keycode == 65293)
		vars->color += PINK;
	render_fractal(vars);
	return (0);
}

static int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == Button5)
		vars->zoom *= 0.6;
	else if (keycode == Button4)
		vars->zoom *= 1.4;
	vars->pos_x += map(x, -1.5, 1.5, WINDOW_WIDTH) * (1 / vars->zoom);
	vars->pos_y += map(y, 1, -1, WINDOW_HEIGHT) * (1 / vars->zoom);
	render_fractal(vars);
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, keydown_hook, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, on_destroy, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_hook, vars);
}
