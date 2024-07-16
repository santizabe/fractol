/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:03:36 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 17:27:22 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

static void	ft_error(const char *str, unsigned char err_type)
{
	if (err_type == 1)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	else
		perror(str);
	exit(EXIT_FAILURE);
}

void	exit_window(void *p)
{
	t_info	*info;

	info = (t_info *)p;
	mlx_close_window(info->mlx);
}

void	key_manager(mlx_key_data_t kd, void *p)
{
	if (kd.key == MLX_KEY_C && kd.action == MLX_PRESS)
		change_color(p);
	else if ((kd.key == MLX_KEY_UP || kd.key == MLX_KEY_DOWN
			|| kd.key == MLX_KEY_RIGHT || kd.key == MLX_KEY_LEFT)
		&& (kd.action == MLX_PRESS || kd.action == MLX_REPEAT))
		arrow_manager(kd, p);
	else if (kd.key == MLX_KEY_ESCAPE && kd.action == MLX_PRESS)
		exit_window(p);
}

int	main(int argc, char **argv)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	if (args_checker(argc, argv))
		return (0);
	if (set_w_h(&info))
		ft_error(mlx_strerror(mlx_errno), 1);
	init_struct(argc, argv, &info);
	info.mlx = mlx_init(info.width, info.height, "Fractol 42", true);
	if (!info.mlx)
		ft_error(mlx_strerror(mlx_errno), 1);
	info.img = mlx_new_image(info.mlx, info.width, info.height);
	if (!info.img)
		ft_error(mlx_strerror(mlx_errno), 1);
	calc_coordinates(&info, argv[1], 1);
	if (info.scroll)
		mlx_loop_hook(info.mlx, &scroll_recalc, (void *)&info);
	mlx_scroll_hook(info.mlx, &zoom, (void *)&info);
	mlx_key_hook(info.mlx, &key_manager, (void *)&info);
	mlx_image_to_window(info.mlx, info.img, 0, 0);
	mlx_loop(info.mlx);
	mlx_delete_image(info.mlx, info.img);
	mlx_terminate(info.mlx);
	return (0);
}
