/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:25:33 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:42:21 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	flip_color(void *pxl)
{
	uchar_t	c;
	uchar_t	c2;
	uchar_t	*tmp;

	tmp = (uchar_t *)pxl;
	c = *tmp;
	c2 = *(tmp + 1);
	*tmp = *(tmp + 2);
	*(tmp + 1) = c;
	*(tmp + 2) = c2;
}

void	change_color(void *param)
{
	t_info	*info;
	int32_t	i;

	i = 0;
	info = (t_info *)param;
	while (i < info->width * info->height)
	{
		flip_color(info->img->pixels + (i * 4));
		i++;
	}
	info->color++;
	if (info->color == 3)
		info->color = 0;
}
