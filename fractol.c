/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:12 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/07 17:08:26 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_fractal(t_vars *vars)
{
	if (vars->type == 'M')
		mandelbrot(vars);
}


int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_input(argc, argv, &vars) == 0)
		return (input_error(argv[0]));
	init_window(&vars, &vars.img);
	init_hooks(&vars);
	show_fractal(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
}
