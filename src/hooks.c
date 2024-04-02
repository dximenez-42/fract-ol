/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:21 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 17:17:11 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	keydown_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		printf("last mouse position\nx:%d\ty:%d\n", vars->mouse_x, vars->mouse_y);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

static int	scroll_hook(int keycode, t_vars *vars)
{
	if (keycode == ON_SCROLL_UP)
		printf("SCROLL UP\n");
	else if (keycode == ON_SCROLL_DOWN)
		printf("SCROLL DOWN\n");
	return (0);
}

static int	mouse_move(int x, int y, t_vars *vars)
{
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 1L<<0, keydown_hook, vars);
	mlx_mouse_hook(vars->win, scroll_hook, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 1L<<0, mouse_move, vars);
}

