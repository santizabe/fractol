/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_recalc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:26:27 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:26:46 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_recalc(void *info)
{
	t_info	*inf;
	int32_t	x;
	int32_t	y;
	char	c;

	inf = (t_info *)info;
	c = inf->fractal[0];
	mlx_get_mouse_pos(inf->mlx, &x, &y);
	if (x < 0 || y < 0 || (x == inf->x && y == inf->y)
		|| (uint32_t)x > inf->img->width
		|| (uint32_t)y > inf->img->height)
		return ;
	inf->x = x;
	inf->y = y;
	inf->xd = inf->r + (x * (1.0 / inf->pxr));
	inf->yd = inf->i + (y * (1.0 / inf->pxr));
	if (c == 'j' || c == 'J' || c == 'G' || c == 'g')
		calc_coordinates(inf, inf->fractal, 0);
}
