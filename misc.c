/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:49:37 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:51:34 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * This is a set of functions that do not deserve
 * their own file, so they were grouped here in
 * order to pass the norminette
 */

void	init_struct(int argc, char **argv, t_info *info)
{
	char	c;

	c = info->fractal[0];
	if (c == 'j' || c == 'J' || c == 'G')
	{
		info->xd = ft_atod(argv[2]);
		if (argc == 3)
			info->yd = ft_atod(argv[2]);
		else if (argc == 4)
			info->yd = ft_atod(argv[3]);
	}
	info->mag = 4.0;
	info->fractal = argv[1];
}

int	set_w_h(t_info *info)
{
	info->mlx = mlx_init(1, 1, "Fractol 42", true);
	if (!info->mlx)
		return (-1);
	mlx_get_monitor_size(0, &info->width, &info->height);
	mlx_terminate(info->mlx);
	info->height = info->height / 2;
	info->width = info->width / 2;
	return (0);
}
