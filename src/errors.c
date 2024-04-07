/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:29:04 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/07 13:53:13 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	input_error(char *p)
{
	ft_printf("Error in the input. Input must be:\n");
	ft_printf("\t%s mandelbrot\n\t%s julia\n", p, p);
	return (1);
}