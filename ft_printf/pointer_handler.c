/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:51:12 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/22 14:13:05 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_longlen(unsigned long num, unsigned int base_len)
{
	int	len;

	len = 1;
	if (num < base_len)
		return (len);
	return (len + ft_longlen(num / base_len, base_len));
}

static void	ft_putlong_base(unsigned long nbr, char *base, int base_len)
{
	char		mod;
	static char	zero_handle;

	if (nbr == 0)
	{
		if (!zero_handle)
			write(1, "0", 1);
		zero_handle = 0;
		return ;
	}
	mod = base[nbr % base_len];
	zero_handle = 1;
	ft_putlong_base(nbr / base_len, base, base_len);
	write(1, &mod, 1);
}

static void	set_w_p_ptr(unsigned char flags, int nlen, int *w_p_h, int *w_p)
{
	w_p_h[0] -= 2;
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

int	handle_pointer(unsigned char flags, int *w_p_h, void *ptr)
{
	unsigned long	nbr;
	int				nlen;
	int				res;
	int				w_p[2];

	nbr = (unsigned long)ptr;
	nlen = ft_longlen(nbr, 16);
	set_w_p_ptr(flags, nlen, w_p_h, &w_p[0]);
	res = 0;
	if (flags & 4)
	{
		res += write(1, "0x", 2);
		res += ft_putlchar(w_p[1], '0');
		ft_putlong_base(nbr, "0123456789abcdef", 16);
		res += ft_putlchar(w_p[0], ' ');
	}
	else
	{
		res += ft_putlchar(w_p[0], ' ');
		res += write(1, "0x", 2);
		res += ft_putlchar(w_p[1], '0');
		ft_putlong_base(nbr, "0123456789abcdef", 16);
	}
	return (nlen + res);
}
