/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:51:07 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/08 16:34:05 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_input(int argc, char **argv, t_vars *vars)
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
		{
			vars->type = 'J';
			vars->julia.r = atod(argv[2]);
			vars->julia.i = atod(argv[3]);
			return (1);
		}
		else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
		{
			vars->type = 'M';
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

int	input_error(char *p)
{
	ft_printf("Error in the input. Input must be:\n");
	ft_printf("\t%s mandelbrot\n\t%s julia <real> <imaginary>\n", p, p);
	return (1);
}
