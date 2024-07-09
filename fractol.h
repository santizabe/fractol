/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:41:51 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/09 05:08:14 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42.h"
# include "ft_printf/ft_printf.h"

typedef unsigned int uint_t;
typedef unsigned char uchar_t;
typedef struct s_info
{
	mlx_t		*mlx;
	mlx_image_t *img;
	char		*fractal;
	double		mag;
	double		r;
	double		i;
	double		xd;
	double		yd;
	double		xmag;
	uint_t		pxr;
	int32_t		x;
	int32_t		y;
	int32_t		width;
	int32_t		height;
	uchar_t		color;
}	t_info;
void	calc_coordinates(t_info *info, char *str, uchar_t i);
void	julia_calc(void *info, void *pixel, double r, double i);
void	mandel_calc(void *inf, void *pixel, double r, double i);

#endif