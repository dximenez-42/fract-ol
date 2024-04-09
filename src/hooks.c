/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:21 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/09 23:57:10 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

static int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (keycode == Button5)
		vars->zoom *= 0.6;
	else if (keycode == Button4)
		vars->zoom *= 1.4;
	render_fractal(vars);
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, keydown_hook, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, on_destroy, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_hook, vars);
}
