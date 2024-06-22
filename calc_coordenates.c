/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:33 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/22 22:09:36 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
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
		ft_memset(pixel, 0xff, 1);
		ft_memset(pixel + 1, i * i, 1);
		ft_memset(pixel + 2, i * i, 1);
		ft_memset(pixel + 3, 245, 1);
	}
}

void	mandelbrot_calc(void *pixel, double r, double i)
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

void	calc_coordinates(mlx_image_t *img)
{
	double	xmag;
	double	pxr;
	double	r;
	double	i;
	int		iter;

	pxr = img->height / 5.0;
	xmag = img->width / pxr;
	r = (xmag / 2) * -1;
	i = -2.5;
	iter = 0;
	while (i < 2.5)
	{
		r = (xmag / 2) * -1;
		while (r < xmag / 2)
		{
			mandelbrot_calc(img->pixels + (iter * 4), r, i);
			iter++;
			r += 1 / pxr;
		}
		i += 1 / pxr;
	}
}
