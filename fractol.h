/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/02 17:23:13 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# ifndef TITLE
#  define TITLE "Fractol"
# endif

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum Mouse {
	ON_LEFT=1,
	ON_RIGHT=2,
	ON_MIDDLE=3,
	ON_SCROLL_UP=4,
	ON_SCROLL_DOWN=5
};

enum Keycodes
{
	ESCAPE=53,
	SPACE=49
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	int		height;
	int		width;
	int		mouse_x;
	int		mouse_y;
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

void	init_window(t_vars *vars, t_data *img, int h, int w);
void	image_to_window(t_vars *vars, int x, int y);
void	put_pixel(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);


void	init_hooks(t_vars *vars);



#endif