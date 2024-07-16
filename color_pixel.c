/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:48:26 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/16 02:09:41 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel(void *pixel, uchar_t i, uchar_t c)
{
	uchar_t	*pxl;
	uchar_t	iter;

	iter = 0;
	pxl = (uchar_t *)pixel;
	if (i == MAX_ITER)
		ft_memset(pxl, 0, 4);
	else
	{
		while (iter < 3)
		{
			if (iter == c)
				ft_memset(pxl + iter, 0x4c, 1);
			else
				ft_memset(pxl + iter, i * i + 105, 1);
			iter++;
		}
		ft_memset(pxl + 3, i * i + 5, 1);
	}
}
