#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
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
	uchar_t		scroll;
}	t_info;
int		ft_isdouble(char *s);
int		args_checker(int argc, char **argv);
int		set_w_h(t_info *info);
void	init_struct(int argc, char **argv, t_info *info);
void	calc_coordinates(t_info *info, char *str, uchar_t i);
void	julia_calc(void *info, void *pixel, double r, double i);
void	mandel_calc(void *inf, void *pixel, double r, double i);
void	ship_calc(void *info, void *pixel, double r, double i);
void	calc_v_line(t_info *info, void *pxl, double i, double r);
void	calc_h_line(t_info *info, void *pxl, double i, double r);
void	arrow_manager(mlx_key_data_t kd, void *p);
void	shift_up(t_info *info);
void	shift_down(t_info *info);
void	shift_right(t_info *info);
void	shift_left(t_info *info);
double	ft_atod(char *s);
void	change_color(void *param);
void	color_pixel(void *pixel, uchar_t i, uchar_t c);
void	scroll_recalc(void *info);
void	zoom(double xd, double yd, void *info);

#endif