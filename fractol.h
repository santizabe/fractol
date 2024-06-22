/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:41:51 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/22 19:54:28 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42.h"
# include "ft_printf/ft_printf.h"

typedef unsigned int uint_t;
typedef unsigned char uchar_t;
void	calc_coordinates(mlx_image_t *img);
typedef struct s_info
{
	mlx_t	*mlx;
	mlx_image_t *img;
}	t_info;

#endif