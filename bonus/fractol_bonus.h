/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:34:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/10 21:16:06 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

// # include "libft/libft.h"
# include "../printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
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

void		init_hooks(t_vars *vars);

void		render_fractal(t_vars *vars);

double		map(double num, double n_min, double n_max, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

double		atod(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			check_input(int argc, char **argv, t_vars *vars);
int			input_error(void);

#endif