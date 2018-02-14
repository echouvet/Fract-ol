/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_iteration.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 20:49:15 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/11 20:49:16 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plus_iteration(t_env *e)
{
	e->im += 5;
}

void	minus_iteration(t_env *e)
{
	e->im -= 5;
	if (e->im < 0)
		e->im = 0;
}

void	zoom_more(t_env *e, int x, int y)
{
	if (x < 0 || x >= e->image_x || y < 0 || y >= e->image_y)
		return ;
	e->x += (double)x / 5;
	e->y += (double)y / 5;
	e->zoom = e->zoom * 1.2;
	e->y = e->y * 1.2;
	e->x = e->x * 1.2;
}

void	zoom_less(t_env *e, int x, int y)
{
	if (x < 0 || x >= e->image_x || y < 0 || y >= e->image_y)
		return ;
	e->x -= x / 5;
	e->y -= y / 5;
	e->zoom = e->zoom / 1.2;
	e->y = e->y / 1.2;
	e->x = e->x / 1.2;
}
