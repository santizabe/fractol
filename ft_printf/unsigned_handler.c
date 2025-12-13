/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:51:18 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 19:14:03 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_w_p(unsigned char flags, int nlen, int *w_p_h, int *w_p)
{
	w_p[1] = w_p_h[1] - nlen;
	w_p[0] = w_p_h[0] - nlen;
	if (w_p[1] > 0)
		w_p[0] = w_p_h[0] - (nlen + w_p[1]);
	if (flags & 2)
	{
		w_p[1] = w_p[0];
		w_p[0] = 0;
	}
}

static int	print_unsigned(unsigned char flags, int *w_p_h, unsigned int nbr)
{
	int	numlen;
	int	res;
	int	width_prec[2];

	numlen = ft_numlen(nbr, 10);
	res = 0;
	if (!w_p_h[1] && !nbr)
		numlen = 0;
	set_w_p(flags, numlen, w_p_h, &width_prec[0]);
	if (flags & 4)
	{
		res += ft_putlchar(width_prec[1], '0');
		if (!(!w_p_h[1] && !nbr))
			ft_putnbr_base(nbr, "0123456789", 10);
		res += ft_putlchar(width_prec[0], ' ');
	}
	else
	{
		res += ft_putlchar(width_prec[0], ' ');
		res += ft_putlchar(width_prec[1], '0');
		if (!(!w_p_h[1] && !nbr))
			ft_putnbr_base(nbr, "0123456789", 10);
	}
	return (numlen + res);
}

int	h_u(unsigned char flags, int *w_p_h, unsigned int nbr, char f)
{
	int	res;

	res = 0;
	if (f == 'u')
		res = print_unsigned(flags, w_p_h, nbr);
	else if (f == 'x')
		res = h_hex(flags, w_p_h, nbr, "0123456789abcdef");
	else
		res = h_hex(flags, w_p_h, nbr, "0123456789ABCDEF");
	return (res);
}
