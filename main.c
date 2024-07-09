/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:03:36 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/09 05:43:28 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

static void ft_error(const char *str, unsigned char err_type)
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

void	flip_color(void *pxl)
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
	// calc_h_line(info, dst + (info->width * 4), info->i + (1.0 / info->pxr), info->r);
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
	// calc_h_line(info, src, im - (1.0 / info->pxr), info->r);
	calc_h_line(info, src + (len * 4), im, info->r);
}

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

void	arrow_manager(mlx_key_data_t kd,void *p)
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

void	key_manager(mlx_key_data_t kd, void *p)
{
	if (kd.key == MLX_KEY_C && kd.action == MLX_PRESS)
		change_color(p);
	else if ((kd.key == MLX_KEY_UP || kd.key == MLX_KEY_DOWN
		|| kd.key == MLX_KEY_RIGHT || kd.key == MLX_KEY_LEFT)
		&& (kd.action == MLX_PRESS || kd.action == MLX_REPEAT))
		arrow_manager(kd, p);

}

void	print_mouse(void *info)
{
	t_info	*inf;
	int32_t	x;
	int32_t	y;
	char	c;

	inf = (t_info *)info;
	c = inf->fractal[0];
	mlx_get_mouse_pos(inf->mlx, &x, &y);
	if (x < 0 || y < 0 || (x == inf->x && y == inf->y)
		|| (uint32_t)x > inf->img->width
		|| (uint32_t)y > inf->img->height)
		return ;
	inf->x = x;
	inf->y = y;
	inf->xd = inf->r + (x * (1.0 / inf->pxr));
	inf->yd = inf->i + (y * (1.0 / inf->pxr));
	if (c == 'j' || c == 'J' || c == 'G' || c == 'g')
		calc_coordinates(inf, inf->fractal, 0);
}

void	zoom(double xd, double yd, void *info)
{
	t_info	*inf;
	int32_t	x;
	int32_t	y;
	double	yres;
	double	xres;

	inf = (t_info *)info;
	yres = 0;
	xres = 0;
	mlx_get_mouse_pos(inf->mlx, &x, &y);
	if (x < 0 || y < 0 || (uint32_t)x > inf->img->width
		|| (uint32_t)y > inf->img->height)
		return ;
	yres = inf->i + (y * 1.0 / inf->pxr);
	xres = inf->r + (x * 1.0 / inf->pxr);
	if (yd > 0 || xd > 0)
	{
		inf->mag = inf->mag - (inf->mag * 0.05);
		inf->pxr = inf->img->height / inf->mag;
		inf->xmag = inf->img->width / inf->pxr;
		inf->i = yres - (y * 1.0 / inf->pxr);
		inf->r = xres - (x * 1.0 / inf->pxr);
		calc_coordinates(inf, inf->fractal, 0);
	}
	else if (inf->mag >= 6.0)
		return ;
	else
	{
		inf->mag = inf->mag + (inf->mag * 0.05);
		inf->pxr = inf->img->height / inf->mag;
		inf->xmag = inf->img->width / inf->pxr;
		inf->i = yres - (y * 1.0 / inf->pxr);
		inf->r = xres - (x * 1.0 / inf->pxr);
		calc_coordinates(inf, inf->fractal, 0);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	info.mag = 4.0;
	info.fractal = argv[1];
	if (args_checker(argc, argv) && print_opt())
		return (0);
	info.mlx = mlx_init(1, 1, "Fractol 42", true);
	if (!info.mlx)
		ft_error(mlx_strerror(mlx_errno), 1);
	mlx_get_monitor_size(0, &info.width, &info.height);
	mlx_terminate(info.mlx);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info.height = info.height / 2;
	info.width = info.width / 2;
	info.mlx = mlx_init(info.width, info.height, "Fractol 42", true);
	if (!info.mlx)
		ft_error(mlx_strerror(mlx_errno), 1);
	info.img = mlx_new_image(info.mlx, info.width, info.height);
	if (!info.img)
		ft_error(mlx_strerror(mlx_errno), 1);
	ft_printf("W: %u    H: %u", info.img->width, info.img->height);
	ft_memset(info.img->pixels, 15, info.img->width * info.img->height * 4);
	calc_coordinates(&info, argv[1], 1);
	mlx_loop_hook(info.mlx, &print_mouse, (void *)&info);
	mlx_scroll_hook(info.mlx, &zoom, (void *)&info);
	mlx_key_hook(info.mlx, &key_manager, (void *)&info);
	mlx_image_to_window(info.mlx, info.img, 0, 0);
	mlx_loop(info.mlx);
	mlx_terminate(info.mlx);
	mlx_delete_image(info.mlx, info.img);
	return (0);
}
