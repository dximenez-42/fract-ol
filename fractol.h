/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/09 00:17:19 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include "libft/libft.h"
# include "printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define PINK 0xFF00FF
# define PURPLE 0x800080
# define LIME_GREEN 0x32CD32
# define CYAN 0x00FFFF
# define YELLOW 0xFFFF00
# define PSYCHO 0xFCBE11

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1500

# define TITLE "Fractol"

# define KC_ESCAPE 0xff1b
# define KC_SPACE 0x0020

# define KC_W 0x0057
# define KC_A 0x0041
# define KC_S 0x0053
# define KC_D 0x0044

# define KC_PLUS 0x002b
# define KC_MINUS 0x002d

# define MC_SCROLL_UP 4
# define MC_SCROLL_DOWN 5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_vars
{
	double		zoom;
	double		pos_x;
	double		pos_y;
	double		color;
	char		type;
	t_complex	input;
	int			iterations;
	double		escape;
	void		*mlx;
	void		*win;
	t_data		img;
}				t_vars;

void		init_window(t_vars *vars, t_data *img);
void		image_to_window(t_vars *vars);
void		put_pixel(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);

void		init_hooks(t_vars *vars);

void		render_fractal(t_vars *vars);

double		map(double num, double n_min, double n_max, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

double		atod(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			check_input(int argc, char **argv, t_vars *vars);
int			input_error(char *p);

#endif