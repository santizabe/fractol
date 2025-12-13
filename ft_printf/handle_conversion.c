/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:07:00 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 19:12:30 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_handler(unsigned char flags, int *w_p_h, char f, va_list ap)
{
	int	res;

	res = 0;
	if (f == 's')
		res += handle_string(flags, w_p_h, va_arg(ap, char *));
	else if (f == 'd' || f == 'i')
		res += handle_int(flags, w_p_h, va_arg(ap, int));
	else if (ft_strchr("uxX", f))
		res += h_u(flags, w_p_h, va_arg(ap, unsigned int), f);
	if (w_p_h[1] == -1)
		w_p_h[1] = 0;
	if (f == 'c')
		res += handle_char(flags, w_p_h, va_arg(ap, int));
	else if (f == '%')
		res += handle_char(flags, w_p_h, '%');
	else if (f == 'p')
		res += handle_pointer(flags, w_p_h, va_arg(ap, void *));
	return (res);
}

int	print_string(char flags, const char **format, va_list ap)
{
	unsigned char	flag_h;
	int				res;
	int				w_p_handler[2];

	flag_h = 0;
	w_p_handler[0] = 0;
	w_p_handler[1] = -1;
	if (flags == -1)
		return (print_err(format, ap));
	if (flags & 1)
		check_flags(format, &flag_h);
	if (flags & 2)
		w_p_handler[0] = check_width(format);
	if (flags & 4 && **format == '.' && ++(*format))
	{
		w_p_handler[1] = check_width(format);
		if (flag_h & 2)
			flag_h = flag_h ^ 2;
	}
	res = conv_handler(flag_h, &w_p_handler[0], **format, ap);
	++(*format);
	return (res);
}
