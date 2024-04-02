/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:51:07 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 19:00:17 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_input(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
			return (1);
		else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
