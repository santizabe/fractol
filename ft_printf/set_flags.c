/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:47:04 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 17:13:19 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 1 = '#'	2 = '0'	4 = '-' 8 = ' ' 16 = '+'
*/
void	set_flags(unsigned char *flags, char c)
{
	if (!(*flags & 1) && c == '#')
		*flags = *flags | 1;
	else if (!(*flags & 4) && (c == '-' || c == '0'))
	{
		if (c == '-')
		{
			*flags = *flags | 4;
			if (*flags & 2)
				*flags = *flags ^ 2;
		}
		else if (c == '0')
			*flags = *flags | 2;
	}
	else if (!(*flags & 16))
	{
		if (c == '+')
		{
			*flags = *flags | 16;
			if (*flags & 8)
				*flags = *flags ^ 8;
		}
		else if (c == ' ')
			*flags = *flags | 8;
	}
}
