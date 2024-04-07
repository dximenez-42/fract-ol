/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/07 17:08:33 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "mlx/mlx.h"
# include <math.h>

#define BLACK	0x000000
#define WHITE	0xFFFFFF
#define PINK 0xFF00FF
#define PURPLE 0x800080
#define LIME_GREEN 0x32CD32
#define CYAN 0x00FFFF
#define YELLOW 0xFFFF00

#  define WINDOW_HEIGHT 720
#  define WINDOW_WIDTH 1280

#  define TITLE "Fractol"

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
	KEY_ESCAPE=53,
	KEY_SPACE=49,
	KEY_W=13,
	KEY_A=0,
	KEY_S=1,
	KEY_D=2,
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_vars {
	double		zoom;
	int			pos_x;
	int			pos_y;
	char		type;
	t_complex	z;
	t_complex	c;
	int			iterations;
	double		escape;
	void		*mlx;
	void		*win;
	t_data		img;
}				t_vars;

void		init_window(t_vars *vars, t_data *img);
void		image_to_window(t_vars *vars, int x, int y);
void		put_pixel(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);

void		init_hooks(t_vars *vars);

void		show_fractal(t_vars *vars);
void		mandelbrot(t_vars *vars);

double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

int			check_input(int argc, char **argv, t_vars *vars);
int			input_error(char *p);

#endif