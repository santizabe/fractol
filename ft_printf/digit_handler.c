/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:02:28 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 19:08:19 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_sign(int n)
{
	int	res;

	res = 0;
	if (n == 1)
		res += write(1, "-", 1);
	else if (n == 2)
		res += write(1, "+", 1);
	else if (n == 3)
		res += write(1, " ", 1);
	return (res);
}

int	print_number(unsigned char flags, int *w_p_s_h, int p, unsigned int n)
{
	int	res;

	res = 0;
	if (flags & 4)
	{
		res += handle_sign(w_p_s_h[2]);
		res += ft_putlchar(w_p_s_h[1], '0');
		if (!(!p && !n))
			ft_putnbr_base(n, "0123456789", 10);
		res += ft_putlchar(w_p_s_h[0], ' ');
	}
	else
	{
		res += ft_putlchar(w_p_s_h[0], ' ');
		res += handle_sign(w_p_s_h[2]);
		res += ft_putlchar(w_p_s_h[1], '0');
		if (!(!p && !n))
			ft_putnbr_base(n, "0123456789", 10);
	}
	return (res);
}

void	set_w_p_s(unsigned char flags, int *w_p_s_h, int *w_p_h, int nlen)
{
	w_p_s_h[1] = w_p_h[1] - nlen;
	w_p_s_h[0] = w_p_h[0] - nlen;
	if (w_p_s_h[1] > 0)
		w_p_s_h[0] = w_p_h[0] - (nlen + w_p_s_h[1]);
	if (flags & 2)
	{
		w_p_s_h[1] = w_p_s_h[0];
		w_p_s_h[0] = 0;
	}
}

int	handle_int(unsigned char flags, int *w_p_h, int num)
{
	int				w_p_s_h[3];
	int				numlen;
	unsigned int	n;

	n = num;
	if (num < 0)
		n = num * -1;
	numlen = ft_numlen(n, 10);
	w_p_s_h[2] = 0;
	if ((flags & 16) || (flags & 8) || num < 0)
	{
		w_p_h[0]--;
		w_p_s_h[2] = 1;
		if (num >= 0)
		{
			w_p_s_h[2] = 2;
			if (flags & 8)
				w_p_s_h[2] = 3;
		}
	}
	if (!w_p_h[1] && !num)
		numlen = 0;
	set_w_p_s(flags, &w_p_s_h[0], w_p_h, numlen);
	return (numlen + print_number(flags, &w_p_s_h[0], w_p_h[1], n));
}

// w = 5, p = 0, nlen = 3 (100) -> w = 2, p = -1 
