/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:24:27 by szapata-          #+#    #+#             */
/*   Updated: 2024/07/12 15:24:56 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *s)
{
	double	res;
	double	fraction;
	char	sign;

	sign = 0;
	res = 0.0;
	fraction = 1.0;
	if ((*s == '-' && --sign) || *s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		res = (res * 10) + (*s - 48);
		s++;
	}
	s++;
	while (ft_isdigit(*s))
	{
		fraction /= 10.0;
		res += (*s - 48) * fraction;
		s++;
	}
	if (sign)
		return (res * -1);
	return (res);
}
