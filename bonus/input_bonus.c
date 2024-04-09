/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:51:07 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/09 23:02:06 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	check_input(int argc, char **argv, t_vars *vars)
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
		{
			vars->type = 'J';
			vars->input.r = atod(argv[2]);
			vars->input.i = atod(argv[3]);
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

int	input_error(char *p)
{
	ft_printf("Error in the input. Input must be:\n");
	ft_printf("\t%s mandelbrot\n", p);
	ft_printf("\t%s julia <real> <imaginary>\n", p);
	ft_printf("\t%s burningship\n", p);
	return (1);
}
