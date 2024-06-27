/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:41:51 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/27 16:20:35 by szapata-         ###   ########.fr       */
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
	double		mag;
}	t_info;
void	calc_coordinates(t_info *img, char *str);

#endif