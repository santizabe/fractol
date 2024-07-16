/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:51:32 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 17:59:11 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	print_opt(uchar_t c)
{
	if (c == 1)
	{
		ft_printf("Please add a valid input:\n");
		ft_printf("\t- Mandelbrot\n\t- Julia\n\t- Ship\n\n");
	}
	else if (c == 2)
	{
		ft_printf("Please specify X & Y coordinates.\n");
		ft_printf("If one parameter is given, it will be\n");
		ft_printf("assigned to both X and Y.\n\n");
	}
	else if (c == 3)
		ft_printf("Please assign valid coordinates.\n\n");
	else if (c == 4)
	{
		ft_printf("Usage: ./fractol \"fractal name\" [x] [y] [-s]");
		ft_printf("error: unrecognized argument: ");
	}
	return (1);
}

static int	check_coord(int argc, char **argv)
{
	if (!ft_isdouble(argv[2]) && print_opt(3))
		return (-1);
	if (argc == 4 && !ft_strncmp(argv[3], "-s", 2))
		return (0);
	else if (argc >= 4 && !ft_isdouble(argv[3]) && print_opt(3))
		return (-1);
	else if (argc == 5 && ft_strncmp(argv[4], "-s", 2)
		&& print_opt(4))
	{
		ft_printf("%s\n", argv[argc - 1]);
		return (-1);
	}
	return (0);
}

int	args_checker(int argc, char **argv)
{
	int		strlen;
	char	c;

	c = argv[1][0];
	if ((argc == 1 || argc > 5) && print_opt(1))
		return (-1);
	strlen = ft_strlen(argv[1]);
	if (!((!ft_strncmp("Mandelbrot", argv[1], strlen)
				|| !ft_strncmp("mandelbrot", argv[1], strlen)
				|| !ft_strncmp("Julia", argv[1], strlen)
				|| !ft_strncmp("julia", argv[1], strlen)
				|| !ft_strncmp("Gaston", argv[1], strlen)
				|| !ft_strncmp("Benoit", argv[1], strlen)
				|| !ft_strncmp("Ship", argv[1], strlen)))
		&& print_opt(1))
		return (-1);
	else if ((c == 'j' || c == 'J' || c == 'G'))
	{
		if ((argc < 3 && print_opt(2))
			|| (check_coord(argc, argv)))
			return (-1);
	}
	return (0);
}
