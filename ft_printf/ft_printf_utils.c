/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:00:56 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/22 14:15:19 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int num, unsigned int base_len)
{
	int	len;

	len = 1;
	if (num < base_len)
		return (len);
	return (len + ft_numlen(num / base_len, base_len));
}

void	ft_putnbr_base(unsigned int nbr, char *base, int base_len)
{
	char		mod;
	static char	zero;

	if (nbr == 0)
	{
		if (!zero)
			write(1, "0", 1);
		zero = 0;
		return ;
	}
	mod = base[nbr % base_len];
	zero = 1;
	ft_putnbr_base(nbr / base_len, base, base_len);
	write(1, &mod, 1);
}

int	ft_putlchar(int len, char c)
{
	int	res;

	res = 0;
	while (res < len)
		res += write(1, &c, 1);
	return (res);
}

int	ft_putnchar(char *s, int count)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i] && i < count)
	{
		res += write(1, &s[i], 1);
		i++;
	}
	return (res);
}
