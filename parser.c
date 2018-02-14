/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:19:43 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/07 06:19:44 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_env *e)
{
	e->m = (t_mdb){-2.1, 0.6, -1.2, 1.2, 0, 0, 0, 0, 0, 0, 0, 0};
	e->im = 50;
	e->zoom = 150;
	e->t = 0.2;
	e->x = 0;
	e->y = 0;
	e->color = 5000000;
}

void	set_burningship(t_env *e)
{
	e->m = (t_mdb){-2.1, 0.6, -1.2, 1.2, 0, 0, 0, 0, 0, 0, 0, 0};
	e->im = 50;
	e->zoom = 150;
	e->t = 0.2;
	e->x = 0;
	e->y = 0;
	e->color = 5000000;
}

void	set_julia(t_env *e)
{
	e->m = (t_mdb){-1, 1, -1.2, 1.2, 0, 0, 0, 0, 0, 0, 0, 0};
	e->im = 50;
	e->zoom = 200;
	e->t = 50;
	e->x = -50;
	e->y = 0;
	e->m.cr = 0.285;
	e->m.ci = 0.01;
	e->color = 5000000;
}

void	envset(t_env *e, char *name)
{
	char	*tmp;

	e->image_x = 500;
	e->image_y = 500;
	if (ft_strcmp(name, "julia") == 0)
		set_julia(e);
	if (ft_strcmp(name, "mandelbrot") == 0)
		set_mandelbrot(e);
	if (ft_strcmp(name, "burningship") == 0)
		set_burningship(e);
	e->pause = 42;
	e->name = name;
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, e->image_x, e->image_y);
	e->win = mlx_new_window(e->mlx, e->image_x, e->image_y, name);
	tmp = mlx_get_data_addr(e->img, &e->bpp, &e->s_l, &e->edn);
	e->pixel = (int*)tmp;
}
