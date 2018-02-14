/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:04:58 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/08 11:04:59 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_hook(int x, int y, t_env *e)
{
	if (e->pause == 42)
	{
		e->m.cr = (double)x / 500;
		e->m.ci = (double)y / 500;
		e->fractal(e);
	}
	else
		return (0);
	return (0);
}

void	julia_maths(t_env *e)
{
	while (e->m.x < e->image_x + e->x)
	{
		e->m.y = e->y;
		while (e->m.y < e->image_y + e->y)
		{
			e->m.zr = e->m.x / e->zoom + e->m.x1;
			e->m.zi = e->m.y / e->zoom + e->m.y1;
			e->m.i = 0;
			while (e->m.zr * e->m.zr + e->m.zi * e->m.zi < 4 && e->m.i < e->im)
			{
				e->m.tmp = e->m.zr;
				e->m.zr = (e->m.zr * e->m.zr) - (e->m.zi * e->m.zi) + e->m.cr;
				e->m.zi = (2 * e->m.zi * e->m.tmp) + e->m.ci;
				e->m.i++;
			}
			e->m.i == e->im ? print(e, e->m.x - e->x, e->m.y - e->y, 0) : \
			print(e, e->m.x - e->x, e->m.y - e->y, (e->color * e->m.i));
			e->m.y++;
		}
		e->m.x++;
	}
}

void	julia(t_env *e)
{
	e->m.x = e->x;
	julia_maths(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
