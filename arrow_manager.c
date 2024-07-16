/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:20:45 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:54:19 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_up(t_info *info)
{
	int		len;
	void	*dst;

	len = (info->width * (info->height - 1)) * 4;
	dst = info->img->pixels + (info->width * 4);
	ft_memmove(dst, info->img->pixels, len);
	info->i = info->i - (1.0 / info->pxr);
	dst = info->img->pixels;
	calc_h_line(info, info->img->pixels, info->i, info->r);
}

void	shift_down(t_info *info)
{
	uint_t	len;
	double	im;
	void	*src;

	len = (info->width * (info->height - 1)) * 4;
	src = info->img->pixels + (info->width * 4);
	ft_memmove(info->img->pixels, src, len);
	info->i = info->i + (1.0 / info->pxr);
	im = info->i + (info->height * (1.0 / info->pxr));
	src = info->img->pixels;
	len = info->width * (info->height - 1);
	calc_h_line(info, src + (len * 4), im, info->r);
}

void	shift_left(t_info *info)
{
	int		j;
	void	*src;
	uint_t	len;

	j = 0;
	len = (info->width - 1) * 4;
	src = info->img->pixels + (j * info->width * 4);
	while (j < info->height)
	{
		src = info->img->pixels + (j * info->width * 4);
		ft_memmove(src + 4, src, len);
		j++;
	}
	info->r = info->r - (1.0 / info->pxr);
	calc_v_line(info, info->img->pixels, info->i, info->r);
}

void	shift_right(t_info *info)
{
	int		j;
	void	*dst;
	uint_t	len;
	double	re;

	j = 0;
	len = (info->width - 1) * 4;
	dst = info->img->pixels + (j * info->width * 4);
	while (j < info->height)
	{
		dst = info->img->pixels + (j * info->width * 4);
		ft_memmove(dst, dst + 4, len);
		j++;
	}
	info->r = info->r + (1.0 / info->pxr);
	re = info->r + (info->width * 1.0 / info->pxr);
	calc_v_line(info, info->img->pixels + len, info->i, re);
}

void	arrow_manager(mlx_key_data_t kd, void *p)
{
	t_info	*info;

	info = (t_info *)p;
	if (kd.key == MLX_KEY_UP)
		shift_up(info);
	else if (kd.key == MLX_KEY_DOWN)
		shift_down(info);
	else if (kd.key == MLX_KEY_LEFT)
		shift_left(info);
	else
		shift_right(info);
}
