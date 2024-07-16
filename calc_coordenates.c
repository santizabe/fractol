/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:33 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/16 00:26:57 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#define MAX_ITER 255
/**
 * @img: img struct;
 * xmag: width magnitude.
 * ypxr: height pixel rate.
 * @return: void.
 */

void	mandel_calc(void *inf, void *pixel, double r, double i)
{
	t_info	*info;
	uint_t	iter;
	double	x;
	double	y;
	double	xtmp;

	info = (t_info *)inf;
	iter = 0;
	xtmp = 0;
	x = 0;
	y = 0;
	while ((x * x) + (y * y) < (2 * 2) && iter < MAX_ITER)
	{
		xtmp = (x * x) - (y * y) + r;
		y = (2 * x * y) + i;
		x = xtmp;
		iter++;
	}
	color_pixel(pixel, iter, info->color);
}

void	julia_calc(void *info, void *pixel, double r, double i)
{
	t_info	*inf;
	uint_t	iter;
	double	xtmp;

	inf = (t_info *)info;
	iter = 0;
	xtmp = 0;
	while ((r * r) + (i * i) < (2 * 2) && iter < MAX_ITER)
	{
		xtmp = (r * r) - (i * i) + inf->xd;
		i = (2 * r * i) + inf->yd;
		r = xtmp;
		iter++;
	}
	color_pixel(pixel, iter, inf->color);
}

void	draw_fractal(t_info *inf, void (*f)(void *, void *, double, double))
{
	double	r;
	double	i;
	void	*pixel;
	uint_t	iterx;
	uint_t	itery;

	r = inf->r;
	i = inf->i;
	iterx = 0;
	itery = 1;
	pixel = inf->img->pixels;
	while (itery <= inf->img->height)
	{
		r = inf->r;
		iterx = (inf->img->width * itery) - inf->img->width;
		while (iterx < inf->img->width * itery)
		{
			(*f)(inf, pixel + (iterx * 4), r, i);
			iterx++;
			r += 1.0 / inf->pxr;
		}
		itery++;
		i += 1.0 / inf->pxr;
	}
}

void	calc_coordinates(t_info *info, char *str, uchar_t i)
{
	if (i)
	{
		info->pxr = info->img->height / info->mag;
		info->i = (info->mag / 2.0) * -1;
		info->xmag = info->img->width / info->pxr;
		info->r = (info->xmag / 2.0) * -1;
	}
	if (str[0] == 'M' || str[0] == 'm' || str[0] == 'B')
		draw_fractal(info, &mandel_calc);
	else
		draw_fractal(info, &julia_calc);
}
