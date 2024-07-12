/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_h_v_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:22:36 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:30:28 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_v_line(t_info *info, void *pxl, double i, double r)
{
	int		j;
	char	c;

	j = 0;
	c = info->fractal[0];
	if (c == 'M' || c == 'm' || c == 'B')
	{
		while (j < info->height)
		{
			mandel_calc(info, pxl + (info->width * j * 4), r, i);
			i += 1.0 / info->pxr;
			j++;
		}
	}
	else
	{
		while (j < info->height)
		{
			julia_calc(info, pxl + (info->width * j * 4), r, i);
			i += 1.0 / info->pxr;
			j++;
		}
	}
}

void	calc_h_line(t_info *info, void *pxl, double i, double r)
{
	int		j;
	char	c;

	j = 0;
	c = info->fractal[0];
	if (c == 'M' || c == 'm' || c == 'B')
	{
		while (j < info->width)
		{
			mandel_calc(info, pxl + (j * 4), r, i);
			r += 1.0 / info->pxr;
			j++;
		}
	}
	else
	{
		while (j < info->width)
		{
			julia_calc(info, pxl + (j * 4), r, i);
			r += 1.0 / info->pxr;
			j++;
		}
	}
}
