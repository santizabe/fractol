/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:03:36 by szapata-          #+#    #+#             */
/*   Updated: 2024/06/22 16:08:48 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

static void ft_error(const char *str, unsigned char err_type)
{
	if (err_type == 1)
		write(2, str, ft_strlen(str));
	else
		perror(str);
	exit(EXIT_FAILURE);
}

int	print_opt(void)
{
	char	*str;

	str = "Please add a valid input:\n\t- Mandelbrot\n\t- Julia\n\n";
	ft_printf(str);
	return (1);
}

int	args_checker(int argc, char **argv)
{
	int	strlen;

	if (argc == 1)
		return (-1);
	strlen = ft_strlen(argv[1]);
	if (!ft_strncmp("Mandelbrot", argv[1], strlen)
		|| !ft_strncmp("mandelbrot", argv[1], strlen)
		|| !ft_strncmp("Julia", argv[1], strlen)
		|| !ft_strncmp("julia", argv[1], strlen)
		|| !ft_strncmp("Gaston", argv[1], strlen)
		|| !ft_strncmp("Benoit", argv[1], strlen))
		return (0);
	return (-1);
}

void	color_mid_w(mlx_image_t *img, uint_t mid_h)
{
	unsigned int	i;
	
	i = 0;
	while (i < img->width)
	{
		ft_memset(img->pixels + (((img->width * mid_h) + i) * 4), 255, 4);
		i++;
	}
}

void	color_cursor_pos(mlx_image_t *img, double xpos, double ypos)
{
	uint_t	x;
	uint_t	y;
	uint_t	res_x;
	uint_t	full;
	
	x = (uint_t)xpos;
	y = (uint_t)ypos;
	res_x = img->width - x;
	full = img->width * img->height;
	if (!x || !y)
		return ;
	if (!y)
		ft_memset(img->pixels + (x * 4), 255, 4);
	else 
		ft_memset(img->pixels + (((y * img->width) - res_x) * 4), 255, 4);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int32_t		width;
	int32_t		height;

	height = 256;
	width = 256;
	if (args_checker(argc, argv) && print_opt())
		return (0);
	info.mlx = mlx_init(width, height, "Fractol 42", true);
	if (!info.mlx)
		ft_error(mlx_strerror(mlx_errno), 1);
	mlx_get_monitor_size(0, &width, &height);
	mlx_terminate(info.mlx);
	info.mlx = mlx_init(width, height, "Fractol 42", true);
	if (!info.mlx)
		ft_error(mlx_strerror(mlx_errno), 1);
	info.img = mlx_new_image(info.mlx, width, height);
	if (!info.img)
		ft_error(mlx_strerror(mlx_errno), 1);
	ft_printf("W: %u    H: %u", info.img->width, info.img->height);
	calc_coordinates(info.img);
	mlx_image_to_window(info.mlx, info.img, 0, 0);
	mlx_loop(info.mlx);
	mlx_terminate(info.mlx);
	return (0);
}
