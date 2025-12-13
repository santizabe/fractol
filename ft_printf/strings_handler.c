/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:38:07 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 18:39:15 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(unsigned char flags, int *w_p_h, int c)
{
	int		width;
	int		res;
	char	d;

	d = (char)c;
	width = w_p_h[0] - 1;
	res = 0;
	if (flags & 4)
	{
		res += write(1, &d, 1);
		res += ft_putlchar(width, ' ');
	}
	else
	{
		res += ft_putlchar(width, ' ');
		res += write(1, &d, 1);
	}
	return (res);
}

int	null_print(unsigned char flags, int width, int p)
{
	int	res;
	int	strlen;

	strlen = 6;
	if (p >= 0 && p < 6)
		strlen = p;
	width -= strlen;
	res = 0;
	if (flags & 4)
	{
		res += write(1, "(null)", strlen);
		res += ft_putlchar(width, ' ');
	}
	else
	{
		res += ft_putlchar(width, ' ');
		res += write(1, "(null)", strlen);
	}
	return (res);
}

int	handle_string(unsigned char flags, int *w_p_h, char *s)
{
	int	width;
	int	strlen;
	int	res;

	strlen = ft_strlen(s);
	res = 0;
	if (w_p_h[1] >= 0 && w_p_h[1] < strlen)
		strlen = w_p_h[1];
	width = w_p_h[0] - strlen;
	if (!s)
		return (null_print(flags, width, w_p_h[1]));
	if (flags & 4)
	{
		res += ft_putnchar(s, strlen);
		res += ft_putlchar(width, ' ');
	}
	else
	{
		res += ft_putlchar(width, ' ');
		res += ft_putnchar(s, strlen);
	}
	return (res);
}
