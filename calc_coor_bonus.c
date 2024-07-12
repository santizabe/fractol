/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:18:58 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:19:22 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#define MAX_ITER 250

void	ship_calc(void *info, void *pixel, double r, double i)
{
	t_info	*inf;
	uint_t	iter;
	double	x;
	double	y;
	double	xtmp;

	inf = (t_info *)info;
	iter = 0;
	xtmp = 0;
	x = 0;
	y = 0;
	while ((x * x) + (y * y) < (2 * 2) && iter < MAX_ITER)
	{
		xtmp = (x * x) - (y * y) + r;
		y = fabs(2.0 * x * y) + i;
		x = xtmp;
		iter++;
	}
	color_pixel(pixel, iter, inf->color);
}
