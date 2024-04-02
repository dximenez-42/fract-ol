/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:21 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 19:16:16 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	keydown_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == KEY_D)
		vars->pos_x += 15;
	else if (keycode == KEY_A)
		vars->pos_x -= 15;
	else if (keycode == KEY_W)
		vars->pos_y -= 15;
	else if (keycode == KEY_S)
		vars->pos_y += 15;
	else
		printf("keycode: %d\n", keycode);
	return (0);
}

static int	scroll_hook(int keycode, t_vars *vars)
{
	if (keycode == ON_SCROLL_UP && vars->zoom < 1000)
		vars->zoom++;
	else if (keycode == ON_SCROLL_DOWN && vars->zoom > 1)
		vars->zoom--;
	return (0);
}

static int	mouse_move_hook(int x, int y, t_vars *vars)
{
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

static int	on_destroy(t_vars *vars)
{
	exit(0);
}

static int	loop_hook(t_vars *vars)
{
	//TODO hacer que se despeje la imagen y renderice el cuadrado en cada refresh
	// vars->img.img = mlx_new_image(vars->mlx, vars->height, vars->width);
	make_square(&vars->img, vars->pos_x, vars->pos_y, create_trgb(0, 0, 0, 255), 200, 200);
	image_to_window(vars, 0, 0);
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, loop_hook, vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L<<0, keydown_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L<<0, on_destroy, vars);
	mlx_mouse_hook(vars->win, scroll_hook, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 1L<<0, mouse_move_hook, vars);
}

