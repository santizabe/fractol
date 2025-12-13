/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:24:38 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/24 01:04:19 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_flag(unsigned char flags, char *base, unsigned int n, int *p)
{
	int	res;

	res = 0;
	if (flags & 1)
	{
		if (n != 0)
		{
			if (base[10] == 'a')
				res += write(1, "0x", 2);
			else if (base[10] == 'A')
				res += write(1, "0X", 2);
		}
		if (flags & 2)
			if (n)
				*p -= 2;
	}
	return (res);
}

static void	set_w_p(unsigned char flags, int nlen, int *w_p_h, int *w_p)
{
	w_p[1] = w_p_h[1] - nlen;
	w_p[0] = w_p_h[0] - nlen;
	if (!w_p[1] && nlen)
		w_p[1] = -1;
	if (w_p[1] > 0)
		w_p[0] = w_p_h[0] - (nlen + w_p[1]);
	if (flags & 2)
	{
		if (w_p[0])
			w_p[1] = w_p[0];
		w_p[0] = 0;
	}
}

int	p_f_h(unsigned char flags, int *w_p, unsigned int n, char *b)
{
	int	res;

	res = 0;
	if ((flags & 1) && n)
		w_p[0] -= 2;
	if (flags & 4)
	{
		res += print_flag(flags, b, n, &w_p[1]);
		res += ft_putlchar(w_p[1], '0');
		if (!(!w_p[1] && !n))
			ft_putnbr_base(n, b, 16);
		res += ft_putlchar(w_p[0], ' ');
	}
	else
	{
		res += ft_putlchar(w_p[0], ' ');
		res += print_flag(flags, b, n, &w_p[1]);
		res += ft_putlchar(w_p[1], '0');
		if (!(!w_p[1] && !n))
			ft_putnbr_base(n, b, 16);
	}
	return (res);
}

int	h_hex(unsigned char flags, int *w_p_h, unsigned int n, char *b)
{
	int	nlen;
	int	res;
	int	w_p[2];

	res = 0;
	nlen = ft_numlen(n, 16);
	if (!w_p_h[1] && !n)
		nlen = 0;
	set_w_p(flags, nlen, w_p_h, &w_p[0]);
	res += p_f_h(flags, &w_p[0], n, b);
	return (nlen + res);
}
