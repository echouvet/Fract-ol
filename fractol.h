/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:19:39 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/06 16:19:42 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct	s_mdb
{
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	int				i;
	long double		x;
	long double		y;
	long double		tmp;
}				t_mdb;

typedef	struct	s_env
{
	long double	x;
	long double	y;
	void		(*fractal)();
	int			image_x;
	int			image_y;
	long		im;
	double		zoom;
	char		*name;
	void		*mlx;
	void		*img;
	void		*win;
	int			bpp;
	int			s_l;
	int			edn;
	int			*pixel;
	double		t;
	int			pause;
	int			color;
	t_mdb		m;
}				t_env;

typedef	struct	s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_color;

void			error(char *str);
void			envset(t_env *e, char *name);
void			mandelbrot(t_env *e);
int				keyhooks(int keycode, t_env *e);
void			mandelbrot_maths(t_env *e);
void			plus_iteration(t_env *e);
void			minus_iteration(t_env *e);
void			zoom_more(t_env *e, int x, int y);
void			zoom_less(t_env *e, int x, int y);
void			print(t_env *e, int x, int y, int color);
void			set_mandelbrot(t_env *e);
void			julia(t_env *e);
void			set_julia(t_env *e);
int				move_hook(int x, int y, t_env *e);
void			color_change(t_env *e);
void			burningship(t_env *e);
void			set_burningship(t_env *e);

#endif
