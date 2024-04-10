/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:51:07 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/10 21:19:54 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	check_valid_args(double x, char *a_x, double y, char *a_y)
{
	if (x == 0 && ft_strncmp(a_x, "0", 1) != 0 && ft_strncmp(a_x, "0.0", 3) != 0
		&& ft_strncmp(a_x, "-0", 2) != 0 && ft_strncmp(a_x, "-0.0", 4) != 0)
	{
		input_error();
		exit(1);
	}
	else if (y == 0 && ft_strncmp(a_y, "0", 1) != 0 && ft_strncmp(a_y, "0.0", 3) != 0
		&& ft_strncmp(a_y, "-0", 2) != 0 && ft_strncmp(a_y, "-0.0", 4) != 0)
	{
		input_error();
		exit(1);
	}
}

int	check_input(int argc, char **argv, t_vars *vars)
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
		{
			vars->type = 'J';
			vars->input.r = atod(argv[2]);
			vars->input.i = atod(argv[3]);
			check_valid_args(vars->input.r, argv[2], vars->input.i, argv[3]);
			return (1);
		}
		else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		{
			vars->type = 'M';
			return (1);
		}
		else if (ft_strncmp(argv[1], "burningship", 11) == 0 && argc == 2)
		{
			vars->type = 'B';
			return (1);
		}
	}
	return (0);
}

int	input_error(void)
{
	ft_printf("Error in the input. Input must be:\n");
	ft_printf("\t./fractol mandelbrot\n");
	ft_printf("\t./fractol julia <real> <imaginary>\n");
	ft_printf("\t./fractol burningship\n");
	return (1);
}
