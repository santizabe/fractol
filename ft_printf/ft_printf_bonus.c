/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:07:44 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 17:15:11 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	ft_printf(char const *format, ...)
{
	int		res;
	char	flags;
	va_list	ap;

	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			flags = check_format(++format);
			res += print_string(flags, &format, ap);
			flags = 0;
			continue ;
		}
		else
			res += write(1, format, 1);
		format++;
	}
	return (res);
}
