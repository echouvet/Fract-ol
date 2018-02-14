/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 07:05:45 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/13 07:05:45 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print(t_env *e, int x, int y, int color)
{
	if (x >= 0 && x < e->image_x && y >= 0 && y < e->image_x)
		e->pixel[y * e->image_x + x] = color;
}

void	error(char *str)
{
	if (ft_strcmp(str, "usage") == 0)
	{
		ft_putendl("Usage: Only input the executable followed by one argument\n\
Acceptable arguments are the following: <julia> <mandelbrot> <burningship>");
		exit(0);
	}
	if (ft_strcmp(str, "malloc") == 0)
	{
		ft_putendl("Error: Memory allocation failed");
		exit(0);
	}
}

void	color_change(t_env *e)
{
	e->color += 10000;
	if (e->color * e->im > 0xFFFFFF)
		e->color = 10;
}
