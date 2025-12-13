/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:40:27 by szapata-          #+#    #+#             */
/*   Updated: 2025/11/14 19:11:34 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_err(const char **format, va_list ap)
{
	int		res;
	void	*ptr;

	res = 0;
	res += write(1, "%", 1);
	ptr = va_arg(ap, void *);
	(void)ptr;
	while (**format && **format != '%')
	{
		res += write(1, *format, 1);
		(*format)++;
	}
	return (res);
}
