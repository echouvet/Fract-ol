/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:17:18 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/06 16:17:19 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		closed(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	exit(42);
	return (0);
}

void	reset(t_env *e)
{
	if (ft_strcmp(e->name, "julia") == 0)
		set_julia(e);
	if (ft_strcmp(e->name, "mandelbrot") == 0)
		set_mandelbrot(e);
	if (ft_strcmp(e->name, "burningship") == 0)
		set_burningship(e);
}

int		keyhooks(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(42);
	if (keycode == 24)
		plus_iteration(e);
	if (keycode == 27)
		minus_iteration(e);
	if (keycode == 49)
		color_change(e);
	if (keycode == 51)
		reset(e);
	if (keycode == 125)
		e->y += 100;
	if (keycode == 126)
		e->y -= 100;
	if (keycode == 124)
		e->x += 100;
	if (keycode == 123)
		e->x -= 100;
	if (keycode == 260)
		e->pause *= -1;
	e->fractal(e);
	return (0);
}

int		mouse_hook(int k, int x, int y, t_env *e)
{
	if (k == 5)
		zoom_more(e, x, y);
	if (k == 1)
		zoom_more(e, x, y);
	if (k == 4)
		zoom_less(e, x, y);
	if (k == 2)
		zoom_less(e, x, y);
	e->fractal(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		error("usage");
	if (ft_strcmp(argv[1], "julia") == 0)
		e.fractal = julia;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		e.fractal = mandelbrot;
	if (ft_strcmp(argv[1], "burningship") == 0)
		e.fractal = burningship;
	if (e.fractal == NULL)
		error("usage");
	envset(&e, argv[1]);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 2, 0, keyhooks, &e);
	mlx_hook(e.win, 6, 64, move_hook, &e);
	mlx_hook(e.win, 17, 0, closed, &e);
	e.fractal(&e);
	mlx_loop(e.mlx);
	return (0);
}
