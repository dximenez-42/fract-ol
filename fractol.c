/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:12 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 18:57:32 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_input(argc, argv) == 0)
		return (input_error(argv[0]));
	init_window(&vars, &vars.img, 1280, 720);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	free(vars.win);
}