/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordenates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:16:33 by szapata-          #+#    #+#             */
/*   Updated: 2025/11/14 19:01:45 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>
#include <math.h>
#define MAX_ITER 255
/**
 * @img: img struct;
 * xmag: width magnitude.
 * ypxr: height pixel rate.
 * @return: void.
 */

 int in_cardioid(double r, double i)
{
    double p = r - 0.25;
    double q = p * p + i * i;

    return (q * (q + p) <= 0.25 * i * i);
}

 int in_bulb(double r, double i)
{
    double x = r + 1.0;
    return (x * x + i * i <= 0.0625);
}

void	mandel_calc(void *inf, void *pixel, double r, double i)
{
	t_info	*info;
	uint_t	iter;
	double	x;
	double	y;
	double	xx;
	double	yy;
	double	xtmp;

	info = (t_info *)inf;
	iter = 0;
	xtmp = 0;
	x = 0;
	y = 0;
	xx = 0;
	yy = 0;
	if (in_cardioid(r, i) || in_bulb(r, i))
        return (color_pixel(pixel, MAX_ITER, info->color));
	while (xx + yy < 4 && iter < MAX_ITER)
	{
		xtmp = xx - yy + r;
		y = (2 * x * y) + i;
		x = xtmp;
		xx = x * x;
		yy = y * y;
		iter++;
	}
	color_pixel(pixel, iter, info->color);
}

void	julia_calc(void *info, void *pixel, double r, double i)
{
	t_info	*inf = (t_info *)info;
	uint_t	iter = 0;
	double	xtmp = 0;
	double	xx = r * r;
	double	yy = i * i;
	double	r_old = r;
	double	i_old = i;
	int		period = 20;
	int		check = period;

	while (xx + yy < 4 && iter < MAX_ITER)
	{
		xtmp = xx - yy + inf->xd;
		i = (2 * r * i) + inf->yd;
		r = xtmp;
		xx = r * r;
		yy = i * i;

		if (!--check)
		{
			if (fabs(r - r_old) < 1e-12 && fabs(i - i_old) < 1e-12)
    			break;
			r_old = r;
			i_old = i;
		}
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
	double	step;
	
	step = 1.0 / inf->pxr;
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
			(*f)(inf, pixel, r, i);
			pixel += 4;
			iterx++;
			r += step;
		}
		itery++;
		i += step;
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
