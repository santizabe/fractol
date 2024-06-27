/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:33 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/27 16:56:20 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#define MAX_ITER 150
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

void	color_pixel(void *pixel, uchar_t i)
{
	if (i == MAX_ITER)
		ft_memset(pixel, 0, 4);
	else
	{
		ft_memset(pixel, 0xfa, 1);
		ft_memset(pixel + 1, i * i, 1);
		ft_memset(pixel + 2, i * i, 1);
		ft_memset(pixel + 3, 245, 1);
	}
}

void	mandel_calc(void *pixel, double r, double i)
{
	uchar_t	iter;
	double	x;
	double	y;
	double	xtmp;
	
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
	color_pixel(pixel, iter);
}

void	julia_calc(void *pixel, double r, double i)
{
	uchar_t	iter;
	double	x;
	double	y;
	double	xtmp;
	
	iter = 0;
	xtmp = 0;
	x = 0.2;
	y = 0.1;
	while ((r * r) + (i * i) < (2 * 2) && iter < MAX_ITER)
	{
		xtmp = (r * r) - (i * i) + x;
		i = (2 * r * i) + y;
		r = xtmp;
		iter++;
	}
	color_pixel(pixel, iter);
}

void	draw_fractal(t_info *inf, void (*f)(void *, double, double))
{
	double	r;
	double	i;
	double	xmag;
	void	*pixel;
	uint_t	pxr;
	uint_t	iterx;
	uint_t	itery;

	pxr = inf->img->height / inf->mag;
	xmag = inf->img->width / pxr;
	r = (xmag / 2) * -1.0;
	i = (inf->mag / 2.0) * -1;
	iterx = 0;
	itery = 1;
	pixel = inf->img->pixels;
	while (itery <= inf->img->height)
	{
		r = (xmag / 2) * -1.0;
		iterx = (inf->img->width * itery) - inf->img->width;
		while (iterx < inf->img->width * itery)
		{
			(*f)(pixel + (iterx * 4), r, i);
			iterx++;
			r += 1.0 / pxr;
		}
		itery++;
		i += 1.0 / pxr;
	}
}

void	calc_coordinates(t_info *info, char *str)
{
	if (str[0] == 'M' || str[0] == 'm' || str[0] == 'B')
		draw_fractal(info, &mandel_calc);
	else
		draw_fractal(info, julia_calc);
}
