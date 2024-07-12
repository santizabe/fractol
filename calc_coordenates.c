/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:33 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:20:15 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#define MAX_ITER 250
/**
 * @img: img struct;
 * xmag: width magnitude.
 * ypxr: height pixel rate.
 * @return: void.
 */

// uint_t	get_rgba(uchar_t r, uchar_t g, uchar_t b, uchar_t a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

void	color_pixel(void *pixel, uchar_t i, uchar_t c)
{
	uchar_t	*pxl;
	uchar_t	iter;

	iter = 0;
	pxl = (uchar_t *)pixel;
	if (i == MAX_ITER)
		ft_memset(pixel, 0, 4);
	else
	{
		while (iter < 3)
		{
			if (iter == c)
				ft_memset(pxl + iter, 0x5a, 1);
			else
				ft_memset(pxl + iter, i * i + 100, 1);
			iter++;
		}
		ft_memset(pixel + 3, 240, 1);
	}
}

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
