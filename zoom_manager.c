/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:32:58 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:43:21 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_variables(t_info *inf, int32_t x, int32_t y)
{
	double	yres;
	double	xres;

	yres = inf->i + (y * 1.0 / inf->pxr);
	xres = inf->r + (x * 1.0 / inf->pxr);
	inf->pxr = inf->img->height / inf->mag;
	inf->xmag = inf->img->width / inf->pxr;
	inf->i = yres - (y * 1.0 / inf->pxr);
	inf->r = xres - (x * 1.0 / inf->pxr);
}

void	zoom(double xd, double yd, void *info)
{
	t_info	*inf;
	int32_t	x;
	int32_t	y;

	inf = (t_info *)info;
	mlx_get_mouse_pos(inf->mlx, &x, &y);
	if (x < 0 || y < 0 || (uint32_t)x > inf->img->width
		|| (uint32_t)y > inf->img->height)
		return ;
	if (inf->mag >= 6.0)
		return ;
	else if (yd > 0 || xd > 0)
		inf->mag = inf->mag - (inf->mag * 0.05);
	else
		inf->mag = inf->mag + (inf->mag * 0.05);
	set_variables(inf, x, y);
	calc_coordinates(inf, inf->fractal, 0);
}
